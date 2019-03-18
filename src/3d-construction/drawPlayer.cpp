#include "drawPlayer.h"

DrawPlayer::CubeVertexArray DrawPlayer::MakeCubeVertexArray(const float &x1, const float &y1, const float &z1,
    const float &x2, const float y2, const float z2)
{
    CubeVertexArray vtxArray;
    auto &vtx=vtxArray.vtxCube;
    auto &col=vtxArray.colCube;
    
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

void DrawPlayer::draw()
{
    //    auto vtxArray = MakeCubeVertexArray(-1,-1,-2,0,0,0);
    float a, b, c;   //the size of bounding box
    a=1; b=1; c=2;
    auto corner = getVtxList();
    auto vtxArray = MakeCubeVertexArray(corner[0], corner[1], corner[2], corner[0]+a, corner[1]+b, corner[2]+c);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtxCube.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.colCube.data());
    glDrawArrays(GL_QUADS,0,24);
    
}

DrawPlayer::DrawPlayer(GamePlayer &player):posVec(player.getPosition())
{
    setVtxList(posVec);
    setColList();
}
DrawPlayer::~DrawPlayer()
{

}

void DrawPlayer::toString()
{
    printf("Player current position: x:%lf  y:%lf  z:%lf\n", getVtxList()[0], getVtxList()[1], getVtxList()[2]);
}

void DrawPlayer::setVtxList(YsVec3 &posVec)
{
    vtx.push_back(posVec[0]);
    vtx.push_back(posVec[1]);
    vtx.push_back(posVec[2]);
}

void DrawPlayer::setColList()
{
    col.push_back(0.0f);
    col.push_back(1.0f);
    col.push_back(0.0f);
    col.push_back(1.0f);
}

std::vector<double> DrawPlayer::getVtxList()
{
    vtx.clear();
    vtx.push_back(posVec[0]);
    vtx.push_back(posVec[1]);
    vtx.push_back(posVec[2]);
    return vtx;
}

std::vector<double> DrawPlayer::getColList()
{
    return col;
}


