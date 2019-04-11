#include "drawPlayer.h"

void DrawPlayer::drawPlayer()
{
    col.clear();
    // printf("VTX SIZE %d\n", stlVtx.size());
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

DrawPlayer::DrawPlayer(GamePlayer &player):stlVtx(player.getVtx())
{
}
DrawPlayer::~DrawPlayer()
{

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