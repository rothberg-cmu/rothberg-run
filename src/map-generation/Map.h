#ifndef ROTHBERG_MAP_HEADER
#define ROTHBERG_MAP_HEADER

#include "ysclass.h"
#include "Road.h"

enum MapSize {
    small, middle, large
    // small = 10 roads; middle = 25 road; large = 50 roads;
};

class Map {

private:
    int roadWidth = 10;
public:
    Map();
    Map(int rN);
    Map(MapSize mapSize);
    ~Map();
    bool isInMap(YsVec3 position);
    bool isInMap(double x, double y, double z);
    bool isInMap(double x, double y);

    std::vector<Road> getRoads();
private:
    void initMap(int rN);
    int roadNum;
    std::vector<Road> roads;

public:
    void dbgPrintRoads();
};

    

#endif