#include "game-player.h"

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


/////////////////////////////////////////////////////////////////


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



GamePlayer::GamePlayer()
{
    aliveStatus = true;
    position[0] = 0;
    position[1] = 0;
    position[2] = 0;
    velocity = 0;
    angle = 0;
}

GamePlayer::~GamePlayer()
{
    CleanUp();
}
void GamePlayer::CleanUp()
{
    aliveStatus = false;
}
YsVec3& GamePlayer::getPosition()
{
    return position;
}
void GamePlayer::setPosition(float x1, float y1, float z1)
{
    position[0] = x1;
    position[1] = y1;
    position[2] = z1;
}
bool GamePlayer::getAliveStatus()
{
    return aliveStatus;
}
void GamePlayer::setAngle(float angle1)
{
    angle = angle1;
}

float GamePlayer::getAngle()
{
    return angle;
}

void GamePlayer::rotate(float angle1)
{
    auto currAngle = getAngle();
    setAngle(currAngle + angle1);
}

void GamePlayer::move(float x1, float y1, float z1)
{
    position[0] = x1;
    position[1] = y1;
    position[2] = z1;
}

void GamePlayer::moveLeft()
{
    auto currPos = getPosition();
    setPosition(currPos[0]-step, currPos[1], currPos[2]);
}

void GamePlayer::moveRight()
{
    auto currPos = getPosition();
    setPosition(currPos[0]+step, currPos[1], currPos[2]);
}

void GamePlayer::moveUp()
{
    auto currPos = getPosition();
    setPosition(currPos[0], currPos[1]+step, currPos[2]);
}

void GamePlayer::moveDown()
{
    auto currPos = getPosition();
    setPosition(currPos[0], currPos[1]-step, currPos[2]);
}

void GamePlayer::draw()
{
    //need to add later
    
    int wid,hei;
    FsGetWindowSize(wid,hei);
    auto aspect=(float)wid/(float)hei;
    
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspect,0.8, 20.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    YsMatrix4x4 modelView;
    modelView.Translate(-2, -2, -10.0);
    //    modelView.RotateYX(angle);
    modelView.RotateYX(getAngle());
    float modelViewF[16];
    modelView.GetOpenGlCompatibleMatrix(modelViewF);
    glMultMatrixf(modelViewF);
    
    //    auto vtxArray = MakeCubeVertexArray(-1,-1,-2,0,0,0);
    float a, b, c;   //the size of bounding box
    a=1; b=1; c=2;
    auto corner = getPosition();
    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
    glDrawArrays(GL_QUADS,0,24);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    //    draw a sphere
    //        sphere1.draw();
    //        glColor3f(1,0,0);
    //        GLUquadric *quad;
    //        quad = gluNewQuadric();
    //        gluSphere(quad,25,100,20);
    //        glTranslatef(0,2,2);
    
}




