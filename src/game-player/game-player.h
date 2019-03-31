#ifndef ROTHBERG_GAMEPLAYER_HEADER
#define ROTHBERG_GAMEPLAYER_HEADER

#include <fslazywindow.h>
#include "ysclass.h"
#include <vector>


class CubeVertexArray
{
public:
    std::vector <float> vtx;
    std::vector <float> col;
};

// add a player class
class GamePlayer
{
    
private:
    bool aliveStatus;
    YsVec3 position;
    float velocity;
    float angle;     // orientation
    double step=0.2;
    
public:
    GamePlayer();
    ~GamePlayer();
    void CleanUp();
    void setPosition(float x1, float y1, float z1);
    YsVec3& getPosition();
    void setAngle(float angle1);
    float getAngle();
    bool getAliveStatus();
    void move(float x1, float y1, float z1);
    void draw();
    void rotate(float angle1);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveWithAngle();
    
};

#endif
