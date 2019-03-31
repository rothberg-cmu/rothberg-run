#include <stdio.h>
#include "binstl.h"



unsigned int GetInteter(const unsigned char dat[4])
{
	unsigned int b0=dat[0];
	unsigned int b1=dat[1];
	unsigned int b2=dat[2];
	unsigned int b3=dat[3];
	return b0+b1*0x100+b2*0x10000+b3*0x1000000;
}

bool CPUIsLittleEndian(void)
{
	int a=1;
	unsigned char *b=((unsigned char *)&a);
	if(1==b[0])
	{
		return true;
	}
	else
	{
		return false;
	}
}

float GetFloat(const unsigned char dat[4])
{
	if(true==CPUIsLittleEndian())
	{
		const float *fPtr=(const float *)dat;
		return *fPtr;
	}
	else
	{
		unsigned char flip[4]={dat[3],dat[2],dat[1],dat[0]};
		const float *fPtr=(const float *)flip;
		return *fPtr;
	}
}



bool LoadBinStl(std::vector <float> &vtx,std::vector <float> &nom,const char fn[])
{
	FILE *fp=fopen(fn,"rb");
	if(nullptr!=fp)
	{
		unsigned char buf[80];

		fread(buf,1,80,fp);


		fread(buf,4,1,fp);
		auto nTri=GetInteter(buf);
		printf("%d\n",nTri);


		int nActual=0;
		while(50==fread(buf,1,50,fp))
		{
			auto nx=GetFloat(buf+0);
			auto ny=GetFloat(buf+4);
			auto nz=GetFloat(buf+8);

			auto x0=GetFloat(buf+12);
			auto y0=GetFloat(buf+16);
			auto z0=GetFloat(buf+20);

			auto x1=GetFloat(buf+24);
			auto y1=GetFloat(buf+28);
			auto z1=GetFloat(buf+32);

			auto x2=GetFloat(buf+36);
			auto y2=GetFloat(buf+40);
			auto z2=GetFloat(buf+44);

			vtx.push_back(x0);
			vtx.push_back(y0);
			vtx.push_back(z0);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			vtx.push_back(x1);
			vtx.push_back(y1);
			vtx.push_back(z1);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			vtx.push_back(x2);
			vtx.push_back(y2);
			vtx.push_back(z2);
			nom.push_back(nx);
			nom.push_back(ny);
			nom.push_back(nz);

			++nActual;
		}


		printf("%d\n",nActual);


		fclose(fp);
		return true;
	}
	return false;
}


