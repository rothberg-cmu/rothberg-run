#include "game-player.h"

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>
#include <math.h>

#include "binstl.h"





//CubeVertexArray MakeCubeVertexArray(float x1,float y1,float z1,float x2,float y2,float z2)
//{
//    CubeVertexArray vtxArray;
//    auto &vtx=vtxArray.vtx;
//    auto &col=vtxArray.col;
//
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//    col.push_back(0);col.push_back(0);col.push_back(1);col.push_back(1);
//
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//    col.push_back(0);col.push_back(1);col.push_back(0);col.push_back(1);
//
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
//    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
//    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
//    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
//    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//    col.push_back(1);col.push_back(0);col.push_back(0);col.push_back(1);
//
//    return vtxArray;
//}






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
    YsVec3 min, max;
    GetBoundingBox(min, max, vtx);
    position = (min + max)/2;
    return position;
}

std::vector <float>& GamePlayer::getVtx()
{
    return vtx;
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
    while (angle1<0) {
        angle1 += 360;
    }
    angle = fmod(angle1, 360);
}

float GamePlayer::getAngle()
{
    while (angle<0)
    {
        angle += 360;
    }
    return angle;
}

void GamePlayer::rotate(float angle1)
{
    
    // step1: find the offset of this point, then use offset to location at the origin
    // step2: rotate using ratation matrix
    // step 3: use -offset to back to the origin location
    
    YsVec3 min,max;
    GetBoundingBox(min,max,vtx);
    
    YsVec3 centroid =(min+max)/2.0;
    float offsetX = centroid.xf();
    float offsetY = centroid.yf();
    printf("offset %f %f\n", offsetX, offsetY);
    
    moveAlongX(-offsetX);
    moveAlongY(-offsetY);
    
    auto currAngle = getAngle()+ angle1;
    setAngle(currAngle);
    float theta = YsPi*(-angle1)/180;
//    printf("cos theta = %f\n",cos(theta));
//    printf("sin theta = %f\n",sin(theta));
    
    for (int i=0; i<vtx.size(); i += 3)
    {
        auto originX = vtx[i];
        auto originY = vtx[i+1];
        
        vtx[i] = originX * cos(theta) - originY * sin(theta);
        vtx[i+1] = originX * sin(theta) + originY * cos(theta);
        
        // easy mode, only two direction
//        switch ((int) angle1) {
//            case 90:
//            {
//                //case of turning +90
//                auto temp = vtx[i+1];
//                vtx[i+1] = -vtx[i];
//                vtx[i] = temp;
//                break;
//            }
//
//
//            case -90:
//            {
//                //case of turning -90
//                auto temp = vtx[i+1];
//                vtx[i+1] = vtx[i];
//                vtx[i] = -temp;
//            }
//
//
//            default:
//                break;
//        }
        
    }
    
    moveAlongX(offsetX);
    moveAlongY(offsetY);
}

void GamePlayer::rotateByStep(float angle2)
{
    if (angle2 <= 10)
    {
        rotate(angle2);
    }
    else
    {
        int slice = fmod(angle2, 10);
        printf("slice = %d\n", slice);
        float angle1 = angle2/slice;
        for ( int i=0; i<slice; i++ )
        {
            rotate(angle1);
        }
    }
}




void GamePlayer::move(float x1, float y1, float z1)
{
    position[0] = x1;
    position[1] = y1;
    position[2] = z1;
}

void GamePlayer::moveLeft()
{
//    auto currPos = getPosition();
//    setPosition(currPos[0]-step, currPos[1], currPos[2]);
    for (int i=0; i<vtx.size(); i += 3)
    {
        vtx[i] -= step;
    }
}

void GamePlayer::moveRight()
{
//    auto currPos = getPosition();
//    setPosition(currPos[0]+step, currPos[1], currPos[2]);
    for (int i=0; i<vtx.size(); i += 3)
    {
        vtx[i] += step;
    }
}

void GamePlayer::moveUp()
{
//    auto currPos = getPosition();
//    setPosition(currPos[0], currPos[1]+step, currPos[2]);
    for (int i=1; i<vtx.size(); i += 3)
    {
        vtx[i] += step;
    }
}

void GamePlayer::moveDown()
{
//    auto currPos = getPosition();
//    setPosition(currPos[0], currPos[1]-step, currPos[2]);
    for (int i=1; i<vtx.size(); i += 3)
    {
        vtx[i] -= step;
    }
}

void GamePlayer::moveWithAngle()
{
    int caseNum;
    int intAngle = (int) angle;
    
    // face up
    if ( 315<intAngle || intAngle <= 45)
    {
        caseNum = 0;
    }
    // face right
    if ( 45 <intAngle && intAngle <= 135)
    {
        caseNum = 1;
    }
    // face down
    if ( 135 <intAngle && intAngle <= 225)
    {
        caseNum = 2;
    }
    // face left
    if ( 225 <intAngle && intAngle <= 315)
    {
        caseNum = 3;
    }
    
    switch (caseNum)
    {
        case 0:
            moveUp();
            break;
        case 1:
            moveRight();
            break;
        case 2:
            moveDown();
            break;
        case 3:
            moveLeft();
            break;
            
        default:
            break;
    }
}

void GamePlayer::moveAlongX(float deltaX)
{
    for (int i=0; i<vtx.size(); i += 3)
    {
        vtx[i] += deltaX;
    }
}

void GamePlayer::moveAlongY(float deltaY)
{
    for (int i=1; i<vtx.size(); i += 3)
    {
        vtx[i] += deltaY;
    }
}

void GamePlayer::moveAlongZ(float deltaZ)
{
    //    printf("vtx data: %s\n", vtx.data());
    for (int i=2; i<vtx.size(); i += 3)
    {
        vtx[i] += deltaZ;
    }
}

void GamePlayer::scale(float scaleFactor)
{
//    float scaleFactor = 1;
    for (int i=0; i<vtx.size(); i++)
    {
        vtx[i] *= scaleFactor;
    }
}


void GamePlayer::LoadBinary()
{
    // load binary file for cartoon figure
    char fileName[] = "cartoonboy.stl";
    if(true==LoadBinStl(vtx, nom, fileName))
    {
        //change y,z coor
        for (int i=0; i<vtx.size(); i+=3)
        {
            auto temp = vtx[i+2];
            vtx[i+2] = vtx[i+1];
            vtx[i+1] = temp;
        }
        
        for(int i=0; i<vtx.size(); i+=3)
        {
            col.push_back(0);
            col.push_back(0);
            col.push_back(1);
            col.push_back(1);
        }
        
        YsVec3 min,max;
        GetBoundingBox(min,max,vtx);
        
        viewTarget=(min+max)/2.0;
        
        auto dim=(max-min).GetLength();
        viewDistance=1.31*dim;
        
        farZ=viewDistance+dim*1.1;
        nearZ=viewDistance-dim*1.1;
        
        printf("STL loaded.\n");
        //transfer to the origin
        auto pos = getPosition();
        moveAlongX(-pos.xf());
        moveAlongY(-pos.yf());
        moveAlongZ(-pos.zf()/2);
        
        GetBoundingBox(min,max,vtx);
        
        // adjust to proper size
        float s = 3/((max.xf()-min.xf())/2);
        printf("scale factor = %f\n", s);
        scale(s);
    
    }
    //
}




void GamePlayer::SetUpHeadLight(void)
{
    float lightParam[4]={0,1/(float)sqrt(2.0),1/(float)sqrt(2.0),0};
    
    glLightfv(GL_LIGHT0,GL_POSITION,lightParam);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}


void GamePlayer::GetBoundingBox(YsVec3 &min,YsVec3 &max,const std::vector <float> &vtx)
{
    min=YsVec3::Origin();
    max=YsVec3::Origin();
    if(3<=vtx.size())
    {
        min.Set(vtx[0],vtx[1],vtx[2]);
        max.Set(vtx[0],vtx[1],vtx[2]);
        for(int i=3; i+3<=vtx.size(); i+=3)
        {
            min.SetX(std::min(min.xf(),vtx[i]));
            min.SetY(std::min(min.yf(),vtx[i+1]));
            min.SetZ(std::min(min.zf(),vtx[i+2]));
            max.SetX(std::max(max.xf(),vtx[i]));
            max.SetY(std::max(max.yf(),vtx[i+1]));
            max.SetZ(std::max(max.zf(),vtx[i+2]));
        }
    }
}

void GamePlayer::draw()
{
    //need to add later
    
//    int wid,hei;
//    FsGetWindowSize(wid,hei);
//    auto aspect=(float)wid/(float)hei;
//
//    glEnable(GL_DEPTH_TEST);
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
//    modelView.Translate(-2, -2, -10.0);
//    //    modelView.RotateYX(angle);
////    modelView.RotateYX(getAngle());
//    float modelViewF[16];
//    modelView.GetOpenGlCompatibleMatrix(modelViewF);
//    glMultMatrixf(modelViewF);
//    
//    //    auto vtxArray = MakeCubeVertexArray(-1,-1,-2,0,0,0);
//    float a, b, c;   //the size of bounding box
//    a=0.5; b=1; c=1;
//    auto corner = getPosition();
//    
//
//    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
//    
//    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
//
//
//    
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);
//
//    glVertexPointer(3,GL_FLOAT,0,vtx.data());
//    glColorPointer(4,GL_FLOAT,0,col.data());
//    glDrawArrays(GL_QUADS,0,24);
//
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
    
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    int wid,hei;
    FsGetWindowSize(wid,hei);
    auto aspect=(float)wid/(float)hei;
    
    glEnable(GL_DEPTH_TEST);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,aspect,nearZ,farZ);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    SetUpHeadLight();
    
    
    YsMatrix4x4 modelView;
    
    modelView.Translate(50,0,-viewDistance+100);
    YsMatrix4x4 viewRot;
    viewRot.RotateXZ(YsPi*60/180);
    viewRot.Invert();
    modelView*=viewRot;
    modelView.Translate(-viewTarget);
    
    float modelViewF[16];
    modelView.GetOpenGlCompatibleMatrix(modelViewF);
    glMultMatrixf(modelViewF);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,vtx.data());
    glNormalPointer(GL_FLOAT,0,nom.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    
}





