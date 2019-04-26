#ifndef OBSTACLE_HEADER
#define OBSTACLE_HEADER

#define OBSTACLES_MIN_DIS 0.5
#define OBSTACLES_PROBABILITY 100
#define OBSTACLES_X_SCALE 40.0
#define OBSTACLES_Y_SCALE 10.0
#define OBSTACLES_Z_SCALE 100.0

#include "Map.h"
#include <vector>
#include <ctime>
#include "binstl.h"
#include <iostream>
#include "fslazywindow.h"
#include <cmath>

class Obstacle {
private:
    YsVec3 pos;
    bool isVertical = false;
    int roadIdx = -1;
public:
    Obstacle(YsVec3& p, bool v, int rd);
    YsVec3 getPos();
    bool getIsVertical();
};

class Obstacles {
private:
    std::vector <Obstacle> obstacles;
    std::vector <float> oneObstacleVtx;
    std::vector <float> oneObstacleCol;
    std::vector <float> oneObstacleNom;
    std::vector <float> vtx;
    std::vector <float> col;
    void initObstacles();
    Map& map;
    int count = 0;
    int prevObjIdx = -1;
public:
    Obstacles(Map& m);
    void restart();
    int getCount();
    void updateCount(YsVec3& pos);
    void loadObstacleStl(const char* fileName);
    int drawObstacles(YsVec3& pos);
};


#endif