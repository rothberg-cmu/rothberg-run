#include "Road.h"
#include <iostream>
#include <cmath>
#include <algorithm>


Road::Road(YsVec3 start, YsVec3 end, double rW) {
    initRoad(start, end, rW);
}

Road::Road(double sx, double sy, double sz, double ex, double ey, double ez, double rW) {
    initRoad(YsVec3(sx, sy, sz), YsVec3(ex, ey, ez), rW);
}

Road::Road(std::vector<YsVec3> vertexes, double rW) {
    if (vertexes.size() < 2) {
        std::cout << "Warning! Not enough vertex to build a road!" << std::endl;
        std::cout << "Building road failure" << std::endl;
        return;
    }
    initRoad(vertexes[0], vertexes[1], rW);
}

Road::~Road() {

}

void Road::initRoad(YsVec3 start, YsVec3 end, double rW) {
    double eps = 1e-2;
    roadStart = start;
    roadEnd = end;
    if (abs(start.x() - end.x()) < eps) {
        isVertical = true;
    } else {
        isVertical = false;
    }
    roadWidth = rW;
    tolerance = rW / 2;
}

bool Road::isInRoad(double x, double y, double z) {
    double maxX = std::max(roadStart.x(), roadEnd.x()) + tolerance;
    double minX = std::min(roadStart.x(), roadEnd.x()) - tolerance;
    double maxY = std::max(roadStart.y(), roadEnd.y()) + tolerance;
    double minY = std::min(roadStart.y(), roadEnd.y()) - tolerance;
    double maxZ = std::max(roadStart.z(), roadEnd.z()) + tolerance;
    double minZ = std::min(roadStart.z(), roadEnd.z()) - tolerance;

    // if (x >= minX && x <= maxX && y >= minY && y <= maxY && z >= minZ && z <= maxZ) {
    //     return true;
    // }
    if (x >= minX && x <= maxX && y >= minY && y <= maxY) {
        return true;
    }
    return false;
}

bool Road::isInRoad(YsVec3 position) {
    return isInRoad(position.x(), position.y(), position.z());
}

bool Road::isInRoad(double x, double y) {
    return isInRoad(x, y, 0);
}

YsVec3 Road::getRoadStart() {
    return roadStart;
}
YsVec3 Road::getRoadEnd() {
    return roadEnd;
}
double Road::getRoadWidth() {
    return roadWidth;
}
bool Road::getIsVertical() {
    return isVertical;
}