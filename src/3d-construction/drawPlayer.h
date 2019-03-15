#ifndef DRAWPLAYER_IS_INCLUDED
#define DRAWPLAYER_IS_INCLUDED

#include <stdio.h>
#include <vector>
#include <ysclass.h>


class DrawPlayer
{
private:
    std::vector<double> vtx, color;
public:
    std::vector<double> getVtxList();
    std::vector<double> getColList();
    std::vector<double> setVtxList(YsVec3 posVec);
    std::vector<double> setColList();
    void draw();
    DrawPlayer(GamePlayer a);
    ~DrawPlayer();
};

#endif