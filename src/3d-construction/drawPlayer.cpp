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

    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    
    
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    
    
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x1); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x1); vtx.push_back(y1); vtx.push_back(z2);
    
    
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z1);
    vtx.push_back(x2); vtx.push_back(y2); vtx.push_back(z2);
    vtx.push_back(x2); vtx.push_back(y1); vtx.push_back(z2);

    if (orientation == 'N')
    {       
        setColList(col, 'r');
        setColList(col, 'r');
        setColList(col, 'g');
        setColList(col, 'g');
        setColList(col, 'b');
        setColList(col, 'b');
    }
    if (orientation == 'E')
    {
        setColList(col, 'r');
        setColList(col, 'r');
        setColList(col, 'b');
        setColList(col, 'b');
        setColList(col, 'g');
        setColList(col, 'g');
    }
    if (orientation == 'S')
    {
        setColList(col, 'r');
        setColList(col, 'r');
        setColList(col, 'g');
        setColList(col, 'g');
        setColList(col, 'b');
        setColList(col, 'b');
    }
    if (orientation == 'W')
    {
        setColList(col, 'r');
        setColList(col, 'r');
        setColList(col, 'b');
        setColList(col, 'b');
        setColList(col, 'g');
        setColList(col, 'g');
    }
    
    return vtxArray;

}

void DrawPlayer::drawCube()
{
    widthCubeX = 0.15;
    widthCubeY = 0.15;
    heightCube = 0.5;
    auto corner = getVtxList();
    auto vtxArray = MakeCubeVertexArray(corner[0]-widthCubeX, corner[1]-widthCubeY, corner[2], corner[0]+widthCubeX, corner[1]+widthCubeY, corner[2]+heightCube);
    
    glVertexPointer(3,GL_FLOAT,0,vtxArray.vtxCube.data());
    glColorPointer(4,GL_FLOAT,0,vtxArray.colCube.data());
    glDrawArrays(GL_QUADS,0,vtxArray.vtxCube.size()/3);
    
}

void DrawPlayer::drawPlayer()
{
    col.clear();
    printf("VTX SIZE %d\n", stlVtx.size());
    for (int i = 0; i <= stlVtx.size()/3; i++)
    {
        if ( i > stlVtx.size()/4) {
            col.push_back(0.407);
            col.push_back(0.262);
            col.push_back(0);
            col.push_back(1);
        }
        else
        {
            col.push_back(0);
            col.push_back(0);
            col.push_back(1);
            col.push_back(0.8);
        }
        
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    // glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    
    glVertexPointer(3,GL_FLOAT,0,stlVtx.data());
    // glNormalPointer(GL_FLOAT,0,nom.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,stlVtx.size()/3);
    
    // glDisableClientState(GL_VERTEX_ARRAY);
    // glDisableClientState(GL_NORMAL_ARRAY);
    // glDisableClientState(GL_COLOR_ARRAY);

}

DrawPlayer::DrawPlayer(GamePlayer &player):posVec(player.getPosition()), stlVtx(player.getVtx())
{
    setVtxList(posVec);
    // setColList();
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

void DrawPlayer::setColList(std::vector<float> &col, char color)
{
    if (color == 'r')
    {
        for (int i = 0; i < 4; i++)
        {
            col.push_back(1.0f);
            col.push_back(0.0f);
            col.push_back(0.0f);
            col.push_back(1.0f);
        }
        
    }
    if (color == 'g')
    {
        for (int i = 0; i < 4; i++)
        {
            col.push_back(0.0f);
            col.push_back(1.0f);
            col.push_back(0.0f);
            col.push_back(1.0f);
        }
        
    }
    if (color == 'b')
    {
        for (int i = 0; i < 4; i++)
        {
            col.push_back(0.0f);
            col.push_back(0.0f);
            col.push_back(1.0f);
            col.push_back(1.0f);
        }
        
    }
    
}

std::vector<double> DrawPlayer::getVtxList()
{
    vtx.clear();
    vtx.push_back(posVec[0]);
    vtx.push_back(posVec[1]);
    vtx.push_back(posVec[2]);
    return vtx;
}

// std::vector<double> DrawPlayer::getColList()
// {
//     return col;
// }


void DrawPlayer::setOrientation(float angle)
{
    if (angle >= 0 && angle < 90)
    {
        orientation = 'N';
    }
    if (angle >= 90 && angle < 180)
    {
        orientation = 'E';
    }
    if (angle >= 180 && angle < 270)
    {
        orientation = 'S';
    }
    if (angle >= 270 && angle < 360)
    {
        orientation = 'W';
    }
}

float DrawPlayer::getWidthCubeX()
{
    return widthCubeX;
}

float DrawPlayer::getWidthCubeY()
{
    return widthCubeY;
}

float DrawPlayer::getHeightCube()
{
    return heightCube;
}

float DrawPlayer::getWidthPlayerX()
{
    return widthPlayerX;
}
float DrawPlayer::getWidthPlayerY()
{
    return widthPlayerY;
}
float DrawPlayer::getHeightPlayer()
{
    return heightPlayer;
}