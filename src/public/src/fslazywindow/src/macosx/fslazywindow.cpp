/* ////////////////////////////////////////////////////////////

File Name: fslazywindow.cpp
Copyright (c) 2017 Soji Yamakawa.  All rights reserved.
http://www.ysflight.com

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//////////////////////////////////////////////////////////// */

#include <fssimplewindow.h>

#include "../fslazywindow.h"

class ArgcArgv
{
public:
	int argc;
	char **argv;
};

static bool InitializeOpenGLCallBack(void *param)
{
	ArgcArgv *arg=(ArgcArgv *)param;

	auto appPtr=FsLazyWindowApplicationBase::GetApplication();
	appPtr->Initialize(arg->argc,arg->argv);
	return true;
}

static void IntervalCallBack(void *)
{
	static bool busy=false;
	if(true!=busy)
	{
		busy=true;
		auto appPtr=FsLazyWindowApplicationBase::GetApplication();
		if(nullptr!=appPtr)
		{
			appPtr->Interval();
		}
		busy=false;
	}
}

static void NeedRedrawCallBack(void *)
{
	auto appPtr=FsLazyWindowApplicationBase::GetApplication();
	if(nullptr!=appPtr)
	{
		appPtr->Draw();
	}
}

static bool UserWantToCloseProgram(void *)
{
	auto appPtr=FsLazyWindowApplicationBase::GetApplication();
	if(nullptr!=appPtr)
	{
		if(true==FsLazyWindowApplicationBase::GetApplication()->UserWantToCloseProgram())
		{
			FsLazyWindowApplicationBase::GetApplication()->BeforeTerminate();
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main(int ac,char *av[])
{
	FsLazyWindowApplicationBase::GetApplication()->BeforeEverything(ac,av);

	FsOpenWindowOption owo;
	owo.useDoubleBuffer=true;
	FsLazyWindowApplicationBase::GetApplication()->GetOpenWindowOption(owo);


	ArgcArgv arg;
	arg.argc=ac;
	arg.argv=av;
	FsRegisterOpenGLInitializationCallBack(InitializeOpenGLCallBack,&arg);

	FsOpenWindow(owo);

	// Memo: Don't register call backs before Initialize.
	//       Some of the call-back functions may be accidentally fired from inside FsOpenWindow.
	FsRegisterIntervalCallBack(IntervalCallBack,nullptr);
	FsRegisterOnPaintCallBack(NeedRedrawCallBack,nullptr);
	FsRegisterCloseWindowCallBack(UserWantToCloseProgram,nullptr);


	auto t0=FsSubSecondTimer();
	while(0!=FsCheckWindowOpen() &&
	      true!=FsLazyWindowApplicationBase::GetApplication()->MustTerminate())
	{
		auto t=FsSubSecondTimer();
		auto passed=t-t0;
		t0=t;

		FsPollDevice();

		// Don't call directly.  IntervalCallBack function prevents re-entrance.
		IntervalCallBack(nullptr);

		auto windowExposure=0!=FsCheckWindowExposure();
		auto needRedraw=FsLazyWindowApplicationBase::GetApplication()->NeedRedraw();
		if(0!=windowExposure || true==needRedraw)
		{
			// FsLazyWindowApplicationBase::GetApplication()->Draw();
			FsPushOnPaintEvent();
		}

		auto sleepMS=FsLazyWindowApplicationBase::GetApplication()->GetMinimumSleepPerInterval();
		if(sleepMS>passed)
		{
			FsSleep(sleepMS-(int)passed);
		}
	}

	FsLazyWindowApplicationBase::GetApplication()->BeforeTerminate();

	FsCloseWindow();

	return 0;
}

#ifdef _WIN32
// Infamouse WinMain function.  This function will be used when SUBSYSTEM is set to WINDOWS.
#include <windows.h>
#include <stdlib.h>

static char *YsStrtok(char **src)
{
	char *r;
	switch(**src)
	{
	case 0:
		return NULL;
	case '\"':
		(*src)++;
		r=(*src);
		while((**src)!='\"' && (**src)!=0)
		{
			(*src)++;
		}
		break;
	default:
		r=(*src);
		while((**src)!=' ' && (**src)!='\t' && (**src)!=0)
		{
			(*src)++;
		}
		break;
	}
	if((**src)!=0)
	{
		(**src)=0;
		(*src)++;
	}
	while((**src)!=0 && ((**src)==' ' || (**src)=='\t'))
	{
		(*src)++;
	}
	return r;
}

static int YsArguments(int *ac,char *av[],int mxac,char *src)
{
	char *arg;
	int len;

	while(*src==' ' || *src=='\t')
	{
		src++;
	}

	len=(int)strlen(src)-1;
	while(len>=0 && isprint(src[len])==0)
	{
		src[len]=0;
		len--;
	}

	*ac=0;
	while((arg=YsStrtok(&src))!=NULL && *ac<mxac)
	{
		av[*ac]=arg;
		(*ac)++;
	}

	if(*ac<mxac)  // 2007/06/22 Added this check.
	{
		av[*ac]=NULL;
	}

	return *ac;
}

int PASCAL WinMain(HINSTANCE inst,HINSTANCE,LPSTR param,int)
{
	int ac;
	static char *av[512],tmp[4096],prog[MAX_PATH];

	strcpy(prog,"Unknown");
	GetModuleFileNameA(inst,prog,260);

	strncpy(tmp,param,256);
	av[0]=prog;

	YsArguments(&ac,av+1,510,tmp);

	return main(ac+1,av);
}
#endif

