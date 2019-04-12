#include "drawPlayer.h"

void DrawPlayer::drawPlayer()
{
    col.clear();
    // printf("VTX SIZE %d\n", stlVtx.size());        
    for(int i=0; i<stlVtx.size()/3; i++)
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


    // for (int i = 0; i <= stlVtx.size()/3; i++)
    // {
    //     if ( i > stlVtx.size()/4) {
    //         col.push_back(0.407);
    //         col.push_back(0.262);
    //         col.push_back(0);
    //         col.push_back(1);
    //     }
    //     else
    //     {
    //         col.push_back(0);
    //         col.push_back(0);
    //         col.push_back(1);
    //         col.push_back(0.8);
    //     }
        
    // }
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