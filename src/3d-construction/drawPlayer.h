#ifndef ROTHBERG_DRAWPLAYER_HEADER
#define ROTHBERG_DRAWPLAYER_HEADER

#include <stdio.h>
#include <vector>
#include <ysclass.h>
#include "game-player.h"
#include "fslazywindow.h"

class DrawPlayer
{
private:
    char orientation = 'N';
    std::vector<double>& vtx;
    std::vector<double> col;
    void setVtxList(YsVec3 &posVec);
    void setColList(std::vector<float> &col, char color);
    float widthCubeX;
    float widthCubeY;
    float heightCube;

    float widthPlayerX;
    float widthPlayerY;
    float heightPlayer;

    YsVec3& posVec;
    class CubeVertexArray
    {
    public:
        std::vector<float> vtxCube;
        std::vector<float> colCube;
    };
    CubeVertexArray MakeCubeVertexArray(const float &x1, const float &y1, const float &z1, const float &x2, const float y2, const float z2);

public:
    std::vector<double> getVtxList();
    std::vector<double> getColList();
    void setOrientation(float angle);
    void toString();
    //draw player as a cube
    void drawCube();
    //draw player as a man
    void drawPlayer();

    float getWidthCubeX();
    float getWidthCubeY();
    float getHeightCube();

    float getWidthPlayerX();
    float getWidthPlayerY();
    float getHeightPlayer();

    DrawPlayer(GamePlayer &player);
    ~DrawPlayer();
};

#endif