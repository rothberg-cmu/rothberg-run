

#include "game-player.h"
#include "Camera.h"
#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>

/*
CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2)
{
    CubeVertexArray vtxArray;
    auto &vtx=vtxArray.vtx;
    auto &col=vtxArray.col;
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
    
    return vtxArray;
}
*/

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
    bool needRedraw;
    
public:
    GamePlayer player;
    Camera camera;
    
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


FsLazyWindowApplication::FsLazyWindowApplication()
{
    needRedraw=false;
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
    player.setPosition(-1, -1, -2);
}

/* virtual */ void FsLazyWindowApplication::Interval(void)
{
    auto key=FsInkey();
    if(FSKEY_ESC==key)
    {
        SetMustTerminate(true);
    }
    
    if(FSKEY_R==key)
    {
        player.rotate(YsPi/10.0);
    }
    
    if(FSKEY_LEFT==key)
    {
        player.moveLeft();
    }
    
    if(FSKEY_RIGHT==key)
    {
        player.moveRight();
    }
    
    if(FSKEY_UP==key)
    {
        player.moveUp();
    }
    
    if(FSKEY_DOWN==key)
    {
        player.moveDown();
    }
    
    needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    int wid,hei;
    FsGetWindowSize(wid,hei);
    auto aspect=(float)wid/(float)hei;
    
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspect,0.8, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    camera.resetMat();
    camera.changeOrientation(player.getAngle());
    
    /*
    YsMatrix4x4 modelView;
    modelView.Translate(-2, -2, -10.0);
    */
    //    modelView.RotateYX(angle);
//    modelView.RotateYX(getAngle());
    float modelViewF[16];
    modelView.GetOpenGlCompatibleMatrix(modelViewF);
    glMultMatrixf(modelViewF);
    
    //    auto vtxArray = MakeCubeVertexArray(-1,-1,-2,0,0,0);
    float a, b, c;   //the size of bounding box
    a=0.5; b=0.5; c=1;
    auto corner = player.getPosition();
    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
    glDrawArrays(GL_QUADS,0,24);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    

    //player.draw();
    
    FsSwapBuffers();
    
    needRedraw=false;
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