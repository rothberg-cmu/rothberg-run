#ifndef OBSTACLE_HEADER
#define OBSTACLE_HEADER

#define OBSTACLES_PROBABILITY 30

#include "Map.h"
#include <vector>
#include <ctime>
#include "binstl.h"
#include <iostream>
#include "fslazywindow.h"

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
public:
    Obstacles(Map& m);
    int getCount();
    void updateCount(YsVec3& pos);
    void loadObstacleStl(const char* fileName);
    void drawObstacles(YsVec3& pos);
};


#endif