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
    std::vector<double> vtx, col;
    void setVtxList(YsVec3 &posVec);
    void setColList();
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
    void toString();
    void draw();
    DrawPlayer(GamePlayer &player);
    ~DrawPlayer();
};

#endif