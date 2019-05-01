
#include "game-player.h"
#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>

class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
    bool needRedraw;
    
public:
    GamePlayer player;
    
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
    player.LoadBinary("../../../src/data/cartoonboy1.stl");
//    player.LoadObject();
    YsVec3 min, max;
    player.GetBoundingBox(min, max, player.vtx);
    player.setPosition((min.xf()+max.xf())/2, (min.yf()+max.yf())/2, (min.zf()+max.zf())/2);

}

/* virtual */ void FsLazyWindowApplication::Interval(void)
{
    auto key=FsInkey();
    if(FSKEY_ESC==key)
    {
        SetMustTerminate(true);
    }
    //right rotate
    if(FSKEY_R==key)
    {
        player.rotate(10);
    }

//    // left rotate
//    if(FSKEY_L==key)
//    {
//        player.rotate(-YsPi/10.0);
//    }
    
    if(FSKEY_LEFT==key)
    {
        player.moveLeftWithAngle();
    }
    
    if(FSKEY_RIGHT==key)
    {
        player.moveRightWithAngle();
    }
    
//    if(FSKEY_UP==key)
//    {
//        player.moveUp();
//    }
//
//    if(FSKEY_DOWN==key)
//    {
//        player.moveDown();
//    }
    
    // w,a,s to control the direction and straight forward
    if(FSKEY_A==key)
    {
        auto tempAngle = player.getAngle();
//        player.setAngle(player.getAngle()+270);
//        player.rotate(player.getAngle()-tempAngle);
        player.rotate(-90);
        printf("current angle: %f \n", player.getAngle());
    }
    
    if(FSKEY_D==key)
    {
        auto tempAngle = player.getAngle();
        printf("before angle: %f \n", player.getAngle());
//        player.setAngle(player.getAngle()+90);
//        player.rotate(player.getAngle()-tempAngle);
        player.rotate(90);
        printf("current angle: %f \n", player.getAngle());
    }
    
    if(FSKEY_W==key)
    {
        // need to refine to move
        player.moveWithAngle();
    }
    
    if(FSKEY_I==key)
    {
        // get info of the player
        auto p1 = player.getPosition();
        printf("current location: %f, %f, %f angle: %f\n", p1.x(), p1.y(),p1.z(), player.getAngle());
    }
    
    if(FSKEY_SPACE==key && player.getJumpMode()==0)
    {
        //set to jump mode
        player.setJumpMode(1);
        printf("jump status:%d \n", player.getJumpMode());
        
////        // get info of the player
//        auto p1 = player.getPosition();
//        printf("current location: %f, %f, %f angle: %f\n", p1.x(), p1.y(),p1.z(), player.getAngle());
//        printf("jump!\n");
    }
    
//    if(FSKEY_X==key)
//    {
//        player.moveAlongX(player.step);
//        auto p1 = player.getPosition();
//        printf("current location: %f, %f, angle: %f\n", p1.x(), p1.y(), player.getAngle());
//    }
//
//    if(FSKEY_Y==key)
//    {
//        player.moveAlongY(player.step);
//        auto p1 = player.getPosition();
//        printf("current location: %f, %f, angle: %f\n", p1.x(), p1.y(), player.getAngle());
//    }
    
   
    
    // judge if in jump mode
    if (player.getJumpMode() != 0)
    {
        printf("jump mode:%d\n",player.getJumpMode());
        switch (player.getJumpMode())
        {
            case 1:
                player.jump(0.2);
                break;
            case 2:
                player.jump(-0.2);
                break;
            default:
                break;
        }
        
        auto currPos = player.getPosition();
        if (currPos.zf()<(0))
        {
            player.setJumpMode(0);
            auto p1 = player.getPosition();
            player.setPosition(p1.xf(), p1.yf(), 0);
            
        }
        //
        if (currPos.zf()>20)
        {
            player.setJumpMode(2);
        }
    }
    
    
    needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    player.draw();
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
