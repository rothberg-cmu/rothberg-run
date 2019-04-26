#include <vector>

#include <ysclass.h>

#include <fslazywindow.h>

#include <ysglfontdata.h>
#include <stdio.h>

#include <string>

#include "drawPlayer.h"
// #include "game-player.h"
//#include "polygonalmesh.h"

#include "DrawingRoad.h"
#include "Camera.h"
#include "../map-generation/Road.h"

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool gameIsOn;
    bool gameIsStart = false;
	bool needRedraw;
	GamePlayer player;
	DrawPlayer drawPlayer = DrawPlayer(player);
	Road road = Road(YsVec3(5.0,0.0,0.0), YsVec3(0.0,0.0,0.0), 1);
	Map map;

	YsMatrix4x4 Rc;
	double d;
	YsVec3 t;
	int score = 0;

	// PolygonalMesh mesh;
	std::vector <float> vtx,nom,col;
	YsVec3 bbx[2];

	static void AddColor(std::vector <float> &col,float r,float g,float b,float a);
	static void AddVertex(std::vector <float> &vtx,float x,float y,float z);
	static void AddNormal(std::vector <float> &nom,float x,float y,float z);

	// void RemakeVertexArray(void);

public:
	FsLazyWindowApplication();
	virtual void BeforeEverything(int argc,char *argv[]);
	virtual void GetOpenWindowOption(FsOpenWindowOption &OPT) const;
	virtual void Initialize(int argc,char *argv[]);
	virtual void Interval(void);
	virtual void BeforeTerminate(void);
	virtual void Draw(void);
	virtual bool UserWantToCloseProgram(void);
	virtual bool MustTerminate(void) const;
	virtual long long int GetMinimumSleepPerInterval(void) const;
	virtual bool NeedRedraw(void) const;
};

/* static */ void FsLazyWindowApplication::AddColor(std::vector <float> &col,float r,float g,float b,float a)
{
	col.push_back(r);
	col.push_back(g);
	col.push_back(b);
	col.push_back(a);
}
/* static */ void FsLazyWindowApplication::AddVertex(std::vector <float> &vtx,float x,float y,float z)
{
	vtx.push_back(x);
	vtx.push_back(y);
	vtx.push_back(z);
}
/* static */ void FsLazyWindowApplication::AddNormal(std::vector <float> &nom,float x,float y,float z)
{
	nom.push_back(x);
	nom.push_back(y);
	nom.push_back(z);
}


FsLazyWindowApplication::FsLazyWindowApplication()
{
	needRedraw=false;
	d=20.0;
	t=YsVec3::Origin();
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{
}
/* virtual */ void FsLazyWindowApplication::GetOpenWindowOption(FsOpenWindowOption &opt) const
{
	opt.x0=0;
	opt.y0=0;
	opt.wid=1200;
	opt.hei=800;
}
/* virtual */ void FsLazyWindowApplication::Initialize(int argc,char *argv[])
{
	gameIsOn = true;
	player.LoadBinary();
	player.scale(0.02);
	player.moveAlongZ(0.25);
	//set road initial position

	map = Map();
	map.dbgPrintRoads();

	DrawingRoad dr;
	dr.drawRoad(map);


	std::vector<float> vtx2 = dr.getVtx();
	std::vector<float> col2 = dr.getCol();
	std::vector<float> nom2 = dr.getNom();
	// printf("length: %d\n", vtx2.size());
	for (float v: vtx2) {
		//printf("v: %f\n", v);
		vtx.push_back(v);
	}

	for (float c: col2) {
		col.push_back(c);
	}

	for (float n: nom2) {
		nom.push_back(n);
	}


}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{	
	// printf("%s\n", gameIsOn ? "True!!!!" : "False!!!!!");
	if (map.isInMap(player.getPosition()) == false)
	{
		if (gameIsOn == true)
		{
			gameIsOn = false;
			// player.setPosition(0, 0, 0);
			printf("OUT OF BOUNDS!!!!!!!!!!!!!!");
			// SetMustTerminate(true);
		}
		
	}

	if (gameIsOn == true)
	{
		player.moveWithAngle();
	}

	auto key=FsInkey();

	if (FSKEY_ENTER == key && gameIsOn == false)
	{
		player.moveAlongX(-player.getPosition()[0]);
		player.moveAlongY(-player.getPosition()[1]);
		gameIsOn = true;
	}
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}
    
	if(FSKEY_LEFT==key)
	{
		if (gameIsOn == true)
		{
			player.moveLeftWithAngle();
		}
		
	}
    if(FSKEY_RIGHT==key)
    {
			if (gameIsOn == true)
			{
				player.moveRightWithAngle();
			}   
    }
    
	// w,a,s to control the direction and straight forward
    if(FSKEY_A==key)
    {
			if (gameIsOn == true)
			{
				player.rotate(-90);
			}
    }
    
    if(FSKEY_D==key)
    {
			if (gameIsOn == true)
			{
				player.rotate(90);
			}
    }
    
    if(FSKEY_W==key)
    {
			if (gameIsOn == true)
			{
			// need to refine to move
					player.moveWithAngle();
			}   
    }
    if (FSKEY_DEL == key && !gameIsStart) {
        gameIsStart = true;
    }

	if(FSKEY_SPACE==key && player.getJumpMode() == 0)
    {
        //set to jump mode
        player.setJumpMode(1);
        // printf("jump status:%d \n", player.getJumpMode());
    }
    

	// judge if in jump mode
    if (player.getJumpMode() != 0)
    {
        // printf("jump mode:%d\n",player.getJumpMode());
        switch (player.getJumpMode())
        {
            case 1:
                player.jump(0.1);
                break;
            case 2:
                player.jump(-0.1);
                break;
            default:
                break;
        }
        
        auto currPos = player.getPosition();
        if (currPos.zf()<0.5)
        {
            player.setJumpMode(0);
            auto p1 = player.getPosition();
            player.setPosition(p1.xf(), p1.yf(), 0);
            
        }
        //
        if (currPos.zf()>2)
        {
            player.setJumpMode(2);
        }
    }
	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	needRedraw=false;

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if (!gameIsStart) {
        glEnable(GL_DEPTH_TEST);
	    int wid,hei;
	    FsGetWindowSize(wid,hei);
	    auto aspect=(double)wid/(double)hei;
	    glViewport(0,0,wid,hei);
	    glMatrixMode(GL_PROJECTION);
	    glLoadIdentity();
        glColor3ub(255,0,0);
        glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);
        glRasterPos2i(wid / 6, hei / 2);
		char str[256];
		sprintf(str,"%s", "please press del to begin");
		YsGlDrawFontBitmap32x48(str);
        FsSwapBuffers();
        return;
    }
	
	

	if (gameIsOn == true && gameIsStart == true)
	{
		
		// YsMatrix4x4 globalToCamera=Rc;
		// globalToCamera.Invert();

		// YsMatrix4x4 modelView;  // need #include ysclass.h
		// modelView.Translate(0,0,-d);
		// modelView*=globalToCamera;
		// modelView.Translate(-t);
		glEnable(GL_DEPTH_TEST);
		int wid,hei;
		FsGetWindowSize(wid,hei);
		auto aspect=(double)wid/(double)hei;
		glViewport(0,0,wid,hei);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0,aspect,d/10.0,d*2.0);

		YsMatrix4x4 modelView = Camera::getCameraMat(player);
		glClearColor(1,1,1,1);
		GLfloat modelViewGl[16];
		modelView.GetOpenGlCompatibleMatrix(modelViewGl);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		GLfloat lightDir[]={0.0f,1.0f/(float)sqrt(2.0f),1.0f/(float)sqrt(2.0f),0.0f};
		glLightfv(GL_LIGHT0,GL_POSITION,lightDir);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glMultMatrixf(modelViewGl);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);

		//draw palyer based on the position and orientation
		drawPlayer.drawPlayer();

		//draw road
		glColorPointer(4,GL_FLOAT,0,col.data());
		glVertexPointer(3,GL_FLOAT,0,vtx.data());
		glNormalPointer(GL_FLOAT,0,nom.data());
		glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);


		glColor3ub(125, 0, 255);
		//display score
		float intAngle = player.getAngle();
		if ( 315<intAngle || intAngle <= 45)
		{
			glRasterPos3f(player.getPosition()[0]-3, player.getPosition()[1] + 1, 2);
		}
		// face right
		if ( 45 <intAngle && intAngle <= 135)
		{
			glRasterPos3f(player.getPosition()[0] + 1, player.getPosition()[1] + 3, 2);
		}
		// face down
		if ( 135 <intAngle && intAngle <= 225)
		{
			glRasterPos3f(player.getPosition()[0] + 3, player.getPosition()[1] - 1, 2);
		}
		// face left
		if ( 225 <intAngle && intAngle <= 315)
		{
			glRasterPos3f(player.getPosition()[0] - 1, player.getPosition()[1] - 3, 2);
		}

		YsGlDrawFontBitmap32x48("Score: ");
		YsGlDrawFontBitmap32x48(std::to_string(score).data());
	}
	else
	{

	    glLoadIdentity();
		//display window to red if game over
		glClearColor( 1, 0, 0, 0.5);
		int wid,hei;
		FsGetWindowSize(wid,hei);

		glViewport(0,0,wid,hei);
		glMatrixMode(GL_PROJECTION);
		glOrtho(0,(float)wid-1,(float)hei-1,0,-1,1);

		glColor3ub(255, 255, 255);
		glRasterPos2i(wid / 3, hei / 3);
        char str[256];
		sprintf(str,"%s", "game over ");
		YsGlDrawFontBitmap32x48(str);//"Game Over!\n Press ENTER to restart or ESC to exit...";
		glRasterPos2i(wid / 6, 2* hei / 3);
		YsGlDrawFontBitmap32x48("press ENTER to restart");
	}
	FsSwapBuffers();
}
/* virtual */ bool FsLazyWindowApplication::UserWantToCloseProgram(void)
{
	return true; // Returning true will just close the program.
}
/* virtual */ bool FsLazyWindowApplication::MustTerminate(void) const
{
	return FsLazyWindowApplicationBase::MustTerminate();
}
/* virtual */ long long int FsLazyWindowApplication::GetMinimumSleepPerInterval(void) const
{
	return 10;
}
/* virtual */ void FsLazyWindowApplication::BeforeTerminate(void)
{
}
/* virtual */ bool FsLazyWindowApplication::NeedRedraw(void) const
{
	return needRedraw;
}


static FsLazyWindowApplication *appPtr=nullptr;

/* static */ FsLazyWindowApplicationBase *FsLazyWindowApplicationBase::GetApplication(void)
{
	if(nullptr==appPtr)
	{
		appPtr=new FsLazyWindowApplication;
	}
	return appPtr;
}
