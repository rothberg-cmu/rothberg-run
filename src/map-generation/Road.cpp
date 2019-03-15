#include "Road.h"
#include <iostream>
#include <cmath>
#include <algorithm>


Road::Road(YsVec3 start, YsVec3 end, int rW) {
    double eps = 1e-2;
    roadStart = start;
    roadEnd = end;
    if (abs(start.x() - end.x()) < eps) {
        isVertical = true;
    } else {
        isVertical = false;
    }
    roadWidth = rW;
    tolerance = rW;
}

Road::Road(int sx, int sy, int sz, int ex, int ey, int ez, int rW) {
    Road(YsVec3(sx, sy, sz), YsVec3(ex, ey, ez), rW);
}

Road::Road(std::vector<YsVec3> vertexes, int rW) {
    if (vertexes.size() < 2) {
        std::cout << "Warning! Not enough vertex to build a road!" << std::endl;
        std::cout << "Building road failure" << std::endl;
        return;
    }
    Road(vertexes[0], vertexes[1], rW);
}

Road::~Road() {

}

bool Road::isInRoad(int x, int y, int z) {
    double maxX = std::max(roadStart.x(), roadEnd.x()) + tolerance;
    double minX = std::min(roadStart.x(), roadEnd.x()) - tolerance;
    double maxY = std::max(roadStart.y(), roadEnd.y()) + tolerance;
    double minY = std::min(roadStart.y(), roadEnd.y()) - tolerance;
    double maxZ = std::max(roadStart.z(), roadEnd.z()) + tolerance;
    double minZ = std::min(roadStart.z(), roadEnd.z()) - tolerance;

    if (x >= minX && x <= maxX && y >= minY && y <= maxY && z >= minZ && z <= maxZ) {
        return true;
    }
    return false;
}

bool Road::isInRoad(YsVec3 position) {
    return isInRoad(position.x(), position.y(), position.z());
}

bool Road::isInRoad(int x, int y) {
    return isInRoad(x, y, 0);
}