#ifndef ROTHBERG_ROAD_HEADER
#define ROTHBERG_ROAD_HEADER

#define ROAD_MIN_LENGTH 10
#define ROAD_MAX_LENGTH 20

#include "ysclass.h"

class Road {
private:
    YsVec3 roadStart;
    YsVec3 roadEnd;
    double roadWidth;
    double tolerance;
    bool isVertical;
public:
    Road(YsVec3 start, YsVec3 end, double rW);
    Road(double sx, double sy, double sz, double ex, double ey, double ez, double rW);
    Road(std::vector<YsVec3> vertexes, double rW);
    ~Road();
    bool isInRoad(YsVec3 position);
    bool isInRoad(double x, double y, double z);
    bool isInRoad(double x, double y);

    YsVec3 getRoadStart();
    YsVec3 getRoadEnd();
    double getRoadWidth();
    bool getIsVertical();
private:
    void initRoad(YsVec3 start, YsVec3 end, double rW);

};

#endif