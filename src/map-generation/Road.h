#ifndef ROTHBERG_ROAD_HEADER
#define ROTHBERG_ROAD_HEADER

#define ROAD_MIN_LENGTH 100
#define ROAD_MAX_LENGTH 500

#include "ysclass.h"

class Road {
private:
public:
    YsVec3 roadStart;
    YsVec3 roadEnd;
    int roadWidth;
    int tolerance;
    bool isVertical;
public:
    Road(YsVec3 start, YsVec3 end, int rW);
    Road(int sx, int sy, int sz, int ex, int ey, int ez, int rW);
    Road(std::vector<YsVec3> vertexes, int rW);
    ~Road();
    bool isInRoad(YsVec3 position);
    bool isInRoad(int x, int y, int z);
    bool isInRoad(int x, int y);

};

#endif