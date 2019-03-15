//#include <iostream>
//using namespace std;
//
//int main()
//{
//    cout << "Hello, World!\n";
//    return 0;
//}


//////////////////////////////////////////////////////////// */

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>

// define a sphere class

//class Sphere
//{
//public:
//    // ctor/dtor
//    Sphere(float radius=1.0f, int sectorCount=36, int stackCount=18, bool smooth=true);
//    ~Sphere() {}
//
//    // getters/setters
//    float getRadius() const                 { return radius; }
//    int getSectorCount() const              { return sectorCount; }
//    int getStackCount() const               { return stackCount; }
//    void set(float radius, int sectorCount, int stackCount, bool smooth=true);
//    void setRadius(float radius);
//    void setSectorCount(int sectorCount);
//    void setStackCount(int stackCount);
//    void setSmooth(bool smooth);
//
//    // for vertex data
//    unsigned int getVertexCount() const     { return (unsigned int)vertices.size() / 3; }
//    unsigned int getNormalCount() const     { return (unsigned int)normals.size() / 3; }
//    unsigned int getTexCoordCount() const   { return (unsigned int)texCoords.size() / 2; }
//    unsigned int getIndexCount() const      { return (unsigned int)indices.size(); }
//    unsigned int getLineIndexCount() const  { return (unsigned int)lineIndices.size(); }
//    unsigned int getTriangleCount() const   { return getIndexCount() / 3; }
//    unsigned int getVertexSize() const      { return (unsigned int)vertices.size() * sizeof(float); }
//    unsigned int getNormalSize() const      { return (unsigned int)normals.size() * sizeof(float); }
//    unsigned int getTexCoordSize() const    { return (unsigned int)texCoords.size() * sizeof(float); }
//    unsigned int getIndexSize() const       { return (unsigned int)indices.size() * sizeof(unsigned int); }
//    unsigned int getLineIndexSize() const   { return (unsigned int)lineIndices.size() * sizeof(unsigned int); }
//    const float* getVertices() const        { return vertices.data(); }
//    const float* getNormals() const         { return normals.data(); }
//    const float* getTexCoords() const       { return texCoords.data(); }
//    const unsigned int* getIndices() const  { return indices.data(); }
//    const unsigned int* getLineIndices() const  { return lineIndices.data(); }
//
//    // for interleaved vertices: V/N/T
//    unsigned int getInterleavedVertexCount() const  { return getVertexCount(); }    // # of vertices
//    unsigned int getInterleavedVertexSize() const   { return (unsigned int)interleavedVertices.size() * sizeof(float); }    // # of bytes
//    int getInterleavedStride() const                { return interleavedStride; }   // should be 32 bytes
//    const float* getInterleavedVertices() const     { return interleavedVertices.data(); }
//
//    // draw in VertexArray mode
//    void draw() const;                                  // draw surface
//    void drawLines(const float lineColor[4]) const;     // draw lines only
//    void drawWithLines(const float lineColor[4]) const; // draw surface and lines
//
//    // debug
//    void printSelf() const;
//
//protected:
//
//private:
//    // member functions
//    void updateRadius();
//    void buildVerticesSmooth();
//    void buildVerticesFlat();
//    void buildInterleavedVertices();
//    void clearArrays();
//    void addVertex(float x, float y, float z);
//    void addNormal(float x, float y, float z);
//    void addTexCoord(float s, float t);
//    void addIndices(unsigned int i1, unsigned int i2, unsigned int i3);
//    std::vector<float> computeFaceNormal(float x1, float y1, float z1,
//                                         float x2, float y2, float z2,
//                                         float x3, float y3, float z3);
//
//    // memeber vars
//    float radius;
//    int sectorCount;                        // longitude, # of slices
//    int stackCount;                         // latitude, # of stacks
//    bool smooth;
//    std::vector<float> vertices;
//    std::vector<float> normals;
//    std::vector<float> texCoords;
//    std::vector<unsigned int> indices;
//    std::vector<unsigned int> lineIndices;
//
//    // interleaved
//    std::vector<float> interleavedVertices;
//    int interleavedStride;                  // # of bytes to hop to the next vertex (should be 32 bytes)
//
//};


// add a player class
class GamePlayer
{
public:
    bool aliveStatus;
    float x0, y0, z0, velocity;
    GamePlayer();
    ~GamePlayer();
    void CleanUp();
    void setPosition(float x1, float y1, float z1);
    void getPosition(void);
    bool getAliveStatus();
    void move(float x1, float y1, float z1);
    void draw();
    
};
GamePlayer::GamePlayer()
{
    aliveStatus = true;
    x0 = 0;
    y0 = 0;
    z0 = 0;
    velocity = 0;
}

GamePlayer::~GamePlayer()
{
    CleanUp();
}
void GamePlayer::CleanUp()
{
    aliveStatus = false;
}
void GamePlayer::getPosition()
{
    return x0, y0, z0;
}
void GamePlayer::setPosition(float x1, float y1, float z1)
{
    x0 = x1;
    y0 = y1;
    z0 = z1;
}
bool GamePlayer::getAliveStatus()
{
    return aliveStatus;
}
void GamePlayer::move(float x1, float y1, float z1)
{
    x0 = x1;
    y0 = y1;
    z0 = z1;
}
void GamePlayer::draw()
{
    //need to add later
    
    int wid,hei;
    FsGetWindowSize(wid,hei);
    auto aspect=(float)wid/(float)hei;
    
    glEnable(GL_DEPTH_TEST);
    
    //draw a sphere
    //    sphere1.draw();
    //    glColor3f(1,0,0);
    //    GLUquadric *quad;
    //    quad = gluNewQuadric();
    //    gluSphere(quad,25,100,20);
    //    glTranslatef(0,2,2);
    //
    
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0,aspect,0.8, 20.0);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//
//    YsMatrix4x4 modelView;
//    modelView.Translate(2, -2, -10.0);
//    modelView.RotateYX(angle);
//    float modelViewF[16];
//    modelView.GetOpenGlCompatibleMatrix(modelViewF);
//    glMultMatrixf(modelViewF);
//
//    auto vtxArray=MakeCubeVertexArray(-1,-1,-2,0,0,0);
//
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//
//    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
//    glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
//    glDrawArrays(GL_QUADS,0,24);
//
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
}




//////////////////////////////////////////////////////////////////
class FsLazyWindowApplication : public FsLazyWindowApplicationBase
{
protected:
    bool needRedraw;
    double angle=0.0;
    
public:
//    Sphere sphere1;  // example for sphere

    class CubeVertexArray
    {
    public:
        std::vector <float> vtx;
        std::vector <float> col;
    };
    
    CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2);
    
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




FsLazyWindowApplication::CubeVertexArray FsLazyWindowApplication::MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2)
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


FsLazyWindowApplication::FsLazyWindowApplication()
{
    needRedraw=false;
}

/* virtual */ void FsLazyWindowApplication::BeforeEverything(int argc,char *argv[])
{
//    sphere1.setRadius(2.0f);
//    sphere1.setSectorCount(72);
//    sphere1.setStackCount(24);
//    sphere1.setSmooth(true);

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
    GamePlayer player;
    
}
/* virtual */ void FsLazyWindowApplication::Interval(void)
{
    auto key=FsInkey();
    if(FSKEY_ESC==key)
    {
        SetMustTerminate(true);
    }
    
    angle+=YsPi/120.0;
    
    needRedraw=true;
}
/* virtual */ void FsLazyWindowApplication::Draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    int wid,hei;
    FsGetWindowSize(wid,hei);
    auto aspect=(float)wid/(float)hei;
    
    glEnable(GL_DEPTH_TEST);
    
    //draw a sphere
    //    sphere1.draw();
    //    glColor3f(1,0,0);
    //    GLUquadric *quad;
    //    quad = gluNewQuadric();
    //    gluSphere(quad,25,100,20);
    //    glTranslatef(0,2,2);
    //
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspect,0.8, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    YsMatrix4x4 modelView;
    modelView.Translate(2, -2, -10.0);
    modelView.RotateYX(angle);
    float modelViewF[16];
    modelView.GetOpenGlCompatibleMatrix(modelViewF);
    glMultMatrixf(modelViewF);
    
    auto vtxArray=MakeCubeVertexArray(-1,-1,-2,0,0,0);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
    glDrawArrays(GL_QUADS,0,24);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
//
    
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
