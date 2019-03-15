#include "Map.h"
#include <iostream>
#include <ctime>


Map::Map() {
    initMap(10);
}

Map::Map(int rN) {
    initMap(rN);
}

Map::Map(MapSize mapSize) {
    switch (mapSize)
    {
        case small:
            initMap(10);
            break;
        case middle:
            initMap(26);
            break;
        case large:
            initMap(50);
        default:
            initMap(10);
            break;
    }
}

void Map::initMap(int rN) {
    roadNum = rN;
    srand(time(NULL));
    YsVec3 origin = YsVec3::Origin();
    YsVec3 start = origin;
    bool isVertical = true;
    for (int i = 0; i < rN - 2; i++) {
        int len = rand() % (ROAD_MAX_LENGTH - ROAD_MIN_LENGTH) + ROAD_MIN_LENGTH;
        int dir = ((i == 0 || rand() % 2) ? 1 : -1);
        YsVec3 end = (isVertical ? YsVec3(start.x(), start.y() + dir * len, start.z()) : 
                                    YsVec3(start.x() + dir * len, start.y(), start.z()));
        Road road(start, end, roadWidth);
        roads.push_back(road);
        start = end;
        isVertical = !isVertical;
    }
    YsVec3 end(start.x(), origin.y(), start.z());
    roads.push_back(Road(start, end, roadWidth));
    roads.push_back(Road(end, origin, roadWidth));
}

Map::~Map() {
}

bool Map::isInMap(double x, double y, double z) {
    for (auto road : roads) {
        if (road.isInRoad(x, y, z)) {
            return true;
        }
    }
    return false;
}

bool Map::isInMap(double x, double y) {
    return isInMap(x, y, 0);
}

bool Map::isInMap(YsVec3 position) {
    return isInMap(position.x(), position.y(), position.z());
}


void Map::dbgPrintRoads() {
    std::cout << roads.size() << std::endl;
    for (auto road : roads) {
        std::cout << "start: " << road.getRoadStart().Txt() << std::endl;
        std::cout << "end: " << road.getRoadEnd().Txt() << std::endl;
        std::cout << std::endl;
    }
}