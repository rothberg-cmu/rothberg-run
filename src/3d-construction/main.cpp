#include <vector>

#include <ysclass.h>

#include <fslazywindow.h>


#include <stdio.h>

#include "drawPlayer.h"
// #include "game-player.h"
//#include "polygonalmesh.h"

#include "DrawingRoad.h"
#include "Camera.h"
#include "../map-generation/Road.h"

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
	bool needRedraw;
	GamePlayer player;
	DrawPlayer drawPlayer = DrawPlayer(player);
	Road road = Road(YsVec3(5.0,0.0,0.0), YsVec3(0.0,0.0,0.0), 0.5);

	YsMatrix4x4 Rc;
	double d;
	YsVec3 t;

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
	player.LoadBinary();
	player.scale(0.1);
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    YsVec3 min, max;
    player.GetBoundingBox(min, max, player.vtx);
    player.setPosition((min.xf()+max.xf())/2, (min.yf()+max.yf())/2, (min.zf()+max.zf())/2);
	//set player initial position
	// player.setPosition(-0.25, -0.25, 0);
	//set road initial position

	Map map = Map();
	map.dbgPrintRoads();

	DrawingRoad dr;
	dr.drawRoad(map);


	std::vector<float> vtx2 = dr.getVtx();
	std::vector<float> col2 = dr.getCol();
	printf("length: %d\n", vtx2.size());
	for (float v: vtx2) {
		printf("v: %f\n", v);
		vtx.push_back(v);
	}

	for (float c: col2) {
		col.push_back(c);
	}

}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
	auto key=FsInkey();
	if(FSKEY_ESC==key)
	{
		SetMustTerminate(true);
	}

	if(FsGetKeyState(FSKEY_Q))
	{
		Rc.RotateXZ(YsPi/60.0);
	}

	if(FSKEY_R==key)
    {
        player.rotate(YsPi/10.0);
		
    }
    
    if(FSKEY_LEFT==key)
    {
		YsVec3 nextMove = YsVec3(player.getPosition()[0]-0.1, player.getPosition()[1], player.getPosition()[2]);
		printf("%s\n", nextMove.Txt());
		player.moveLeft();
		drawPlayer.toString();
		printf("real: x %lf y: %lf z:%lf\n", player.getPosition()[0],player.getPosition()[1],player.getPosition()[2]);
	}
    if(FSKEY_RIGHT==key)
    {
        player.moveRight();
		drawPlayer.toString();
		printf("real: x %lf y: %lf z:%lf\n", player.getPosition()[0],player.getPosition()[1],player.getPosition()[2]);
    }
    
    if(FSKEY_UP==key)
    {
        player.moveUp();
		drawPlayer.toString();
		printf("real: x %lf y: %lf z:%lf\n", player.getPosition()[0],player.getPosition()[1],player.getPosition()[2]);
    }
    
    if(FSKEY_DOWN==key)
    {
        player.moveDown();
		drawPlayer.toString();
		printf("real: x %lf y: %lf z:%lf\n", player.getPosition()[0],player.getPosition()[1],player.getPosition()[2]);
    }
	// w,a,s to control the direction and straight forward
    if(FSKEY_A==key)
    {

        player.setAngle(player.getAngle()+270);
        printf("current angle: %f \n", player.getAngle());
    }
    
    if(FSKEY_D==key)
    {
        player.setAngle(player.getAngle()+90);
        printf("current angle: %f \n", player.getAngle());
    }
    
    if(FSKEY_W==key)
    {
        // need to refine to move
        player.moveWithAngle();
    }
    


	needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
	needRedraw=false;

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	int wid,hei;
	FsGetWindowSize(wid,hei);
	auto aspect=(double)wid/(double)hei;
	glViewport(0,0,wid,hei);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,aspect,d/10.0,d*2.0);

	YsMatrix4x4 modelView = Camera::getCameraMat(player);

	// YsMatrix4x4 globalToCamera=Rc;
	// globalToCamera.Invert();

	// YsMatrix4x4 modelView;  // need #include ysclass.h
	// modelView.Translate(0,0,-d);
	// modelView*=globalToCamera;
	// modelView.Translate(-t);

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
	// glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//draw palyer based on the position and orientation
	float angle = player.getAngle();
	drawPlayer.setOrientation(angle);
	drawPlayer.drawPlayer();

	//draw road
	glColorPointer(4,GL_FLOAT,0,col.data());
	// glNormalPointer(GL_FLOAT,0,nom.data());
	glVertexPointer(3,GL_FLOAT,0,vtx.data());
	glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
	glDisableClientState(GL_VERTEX_ARRAY);
	// glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	// DrawPlayer drawPlayer = DrawPlayer(player);
	// drawPlayer.toString();
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
