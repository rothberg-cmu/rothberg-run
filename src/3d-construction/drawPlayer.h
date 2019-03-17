#ifndef ROTHBERG_DRAWPLAYER_HEADER
#define ROTHBERG_DRAWPLAYER_HEADER

#include <stdio.h>
#include <vector>
#include <ysclass.h>
#include "game-player.h"

class DrawPlayer
{
private:
    std::vector<double> vtx, col;
    void setVtxList(YsVec3 &posVec);
    void setColList();
    YsVec3 posVec;
public:
    std::vector<double> getVtxList();
    std::vector<double> getColList();
    void toString();
    void draw();
    DrawPlayer(GamePlayer &player);
    ~DrawPlayer();
};

#endif