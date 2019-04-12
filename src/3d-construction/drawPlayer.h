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
    std::vector<float>& stlVtx;
    std::vector<float> col;

    float widthPlayerX;
    float widthPlayerY;
    float heightPlayer;

public:
    //draw player as a man
    void drawPlayer();

    float getWidthPlayerX();
    float getWidthPlayerY();
    float getHeightPlayer();

    DrawPlayer(GamePlayer &player);
    ~DrawPlayer();
};

#endif