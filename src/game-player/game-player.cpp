#include "game-player.h"

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>
#include <math.h>

#include "binstl.h"
#include <string>
//#include "yspng.h"




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
//    position[0] = x1;
//    position[1] = y1;
//    position[2] = z1;
    position.SetX(x1);
    position.SetY(y1);
    position.SetZ(z1);
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


void GamePlayer::moveLeftWithAngle()
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
            moveLeft();
            break;
        case 1:
            moveUp();
            break;
        case 2:
            moveLeft();
            break;
        case 3:
            moveDown();
            break;
            
        default:
            break;
    }
}


void GamePlayer::moveRightWithAngle()
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
            moveRight();
            break;
        case 1:
            moveDown();
            break;
        case 2:
            moveRight();
            break;
        case 3:
            moveUp();
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

void GamePlayer::jump()
{
    moveAlongZ(5.0);
    auto pos = getPosition();
    pos.SetZ(pos.zf()+5.0);
    setPosition(pos.xf(), pos.yf(), pos.zf());
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
//    char fileName[] = "../../src/3d-construction/cartoonboy.stl";
    char fileName[] = "cartoonboy1.stl";
    if(true==LoadBinStl(vtx, nom, fileName))
    {
        //change y,z coor
        for (int i=0; i<vtx.size(); i+=3)
        {
            auto temp = vtx[i+2];
            vtx[i+2] = vtx[i+1];
            vtx[i+1] = temp;
        }
        
        for(int i=0; i<vtx.size()/3; i++)
        {
            if (i>116000) // hat color
            {
                col.push_back(1);
                col.push_back(0.3);
                col.push_back(0.3);
                col.push_back(1);
            }
            else if(i>111000) //right foot color
                {
                    col.push_back(1);
                    col.push_back(0.55);
                    col.push_back(0.1);
                    col.push_back(1);
                }
                else if(i>110000) //pocket
                {
                    col.push_back(0.4);
                    col.push_back(0.6);
                    col.push_back(1);
                    col.push_back(1);
                }
                    else if(i>95000) //sweater
                    {
                        col.push_back(0);
                        col.push_back(0.4);
                        col.push_back(0.13);
                        col.push_back(1);
                    }
                        else if(i>80000) //eye
                        {
                            col.push_back(0);
                            col.push_back(0);
                            col.push_back(0);
                            col.push_back(1);
                        }
                            else if(i>35000) //skin
                            {
                                col.push_back(1);
                                col.push_back(0.9);
                                col.push_back(0.8);
                                col.push_back(1);
                            }
                                else if(i>30000) //left foot
                                {
                                    col.push_back(1);
                                    col.push_back(0.55);
                                    col.push_back(0.1);
                                    col.push_back(1);
                                }
                                    else if(i<1500) //mouth
                                    {
                                        col.push_back(1);
                                        col.push_back(0);
                                        col.push_back(0);
                                        col.push_back(1);
                                    }
            
            else // jeans
            {
                col.push_back(0);
                col.push_back(0.48);
                col.push_back(0.8);
                col.push_back(1);
            }

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
        scale(s*4);
        printf("size of vtx:%d\n", vtx.size());
    
        
//        // test for load png
//        FsChangeToProgramDir();
//        YsRawPngDecoder png;
//        if(YSOK==png.Decode("grass.png"))
//        {
//            printf("%d %d\n",png.wid,png.hei);
//            png.Flip();
//        }
//        else
//        {
//            printf("Cannot open.\n");
//        }
        
        
    }
}

void GamePlayer::LoadObject()
{
    std::vector <YsVec3>temp_vtx;
    std::vector <YsVec2>temp_uv;
    std::vector <YsVec3>temp_nom;
     std::vector <YsVec3>vtx3;
    
    std::vector <int>vertexIndices, uvIndices, normalIndices;
    
    char fileName[] = "cartoonboy.obj";
    FILE *fp=fopen(fileName,"rb");
    if( fp == NULL )
    {
        printf("Impossible to open the file !\n");
    }
    if(nullptr!=fp)
    {
        printf("file opened!\n");
    }
    
    // read this file until the end :
    while( 1 )
    {
        
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(fp, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.
        
        // else : parse lineHeader
        //deal with the vertices
        if ( strcmp( lineHeader, "v" ) == 0 )
        {
            
            float x0, y0, z0;
            fscanf(fp, "%f %f %f\n", &x0, &y0, &z0);
            YsVec3 vertex;
            vertex.SetX(x0);
            vertex.SetY(y0);
            vertex.SetZ(z0);
            temp_vtx.push_back(vertex);
//            temp_vtx.push_back(x0);
//            temp_vtx.push_back(y0);
//            temp_vtx.push_back(z0);
//            vtx.push_back(x0);
//            vtx.push_back(y0);
//            vtx.push_back(z0);

        }
        else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
            float tx, ty;
            fscanf(fp, "%f %f\n", &tx, &ty );
            YsVec2 uv;
            uv.SetX(tx);
            uv.SetY(ty);
            temp_uv.push_back(uv);
//            temp_uv.push_back(tx);
//            temp_uv.push_back(ty);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
            float nx, ny, nz;
            fscanf(fp, "%f %f %f\n", &nx, &ny, &nz );
            YsVec3 normal;
            normal.SetX(nx);
            normal.SetY(ny);
            normal.SetZ(nz);
            temp_nom.push_back(normal);
//            temp_nom.push_back(nx);
//            temp_nom.push_back(ny);
//            temp_nom.push_back(nz);
//            nom.push_back(nx);
//            nom.push_back(ny);
//            nom.push_back(nz);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 )
        {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(fp, "%d/%d/%d %d/%d/%d %d/%d/%dn", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("File can't be read by our simple parser : ( Try exporting with other optionsn");
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
            
//            printf("%d\n", vertexIndex[0]);
//            printf("%d\n", vertexIndex[1]);
//            printf("%d\n", vertexIndex[2]);
//            printf("%d\n", vertexIndex[3]);
            
        }
    }
    
    for( unsigned int i=0; i<temp_vtx.size(); i++)
    {
        unsigned int vertexIndex = vertexIndices[i];
        YsVec3 vertex1 = temp_vtx[ vertexIndex-1 ];
        vtx3.push_back(vertex1);
    }
    
    for (int i=0; i<vtx3.size(); i++)
    {
        vtx.push_back(vtx3[i].xf());
        vtx.push_back(vtx3[i].yf());
        vtx.push_back(vtx3[i].zf());
    }

    printf("size of vtx:%d\n", vtx.size());
//
    YsVec3 min,max;
    GetBoundingBox(min,max,vtx);

    viewTarget=(min+max)/2.0;

    auto dim=(max-min).GetLength();
    viewDistance=1.31*dim;

    farZ=viewDistance+dim*1.1;
    nearZ=viewDistance-dim*1.1;

    printf("OBJ loaded.\n");
    //transfer to the origin
    auto pos = getPosition();
    moveAlongX(-pos.xf());
    moveAlongY(-pos.yf());
    moveAlongZ(-pos.zf()/2);

    GetBoundingBox(min,max,vtx);

//     adjust to proper size
    float s = 3/((max.xf()-min.xf())/2);
    printf("scale factor = %f\n", s);
    scale(s);
    
    for(int i=0; i<vtx.size(); i+=3)
    {
        col.push_back(0);
        col.push_back(0);
        col.push_back(1);
        col.push_back(1);
    }
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
    
    modelView.Translate(50,0,-viewDistance);
//    modelView.Translate(0,0,-viewDistance);
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
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3-5392);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    
}





