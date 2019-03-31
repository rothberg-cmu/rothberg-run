#include "game-player.h"

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>
#include <math.h>




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
    angle = fmod(angle1, 360);
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

void GamePlayer::moveWithAngle()
{
    switch ((int) angle)
    {
        case 0:
            moveUp();
            break;
        case 90:
            moveRight();
            break;
        case 180:
            moveDown();
            break;
        case 270:
            moveLeft();
            break;
            
        default:
            break;
    }
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
//    modelView.RotateYX(getAngle());
    float modelViewF[16];
    modelView.GetOpenGlCompatibleMatrix(modelViewF);
    glMultMatrixf(modelViewF);
    
    //    auto vtxArray = MakeCubeVertexArray(-1,-1,-2,0,0,0);
    float a, b, c;   //the size of bounding box
    a=0.5; b=0.5; c=1;
    auto corner = getPosition();
    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtx.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.col.data());
    glDrawArrays(GL_QUADS,0,24);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    
}




