#ifndef OBSTACLE_HEADER
#define OBSTACLE_HEADER

#define OBSTACLES_PROBABILITY 30

#include "Map.h"
#include <vector>

class Obstacle {
private:
    YsVec3 pos;
    bool isVertical = false;
    int roadIdx = -1;
public:
    Obstacle(YsVec);
};

class Obstacles {
private:
    void initObstacles();
    Map& map;
    int count = 0;
public:
    Obstacles(Map& m);
    int getCount();
    void updateCount(YsVec3& pos);
};


#endif