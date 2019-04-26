
#include "Obstacle.h"

Obstacle::Obstacle(YsVec3& p, bool v, int rd) {
    pos = p;
    isVertical = v;
    roadIdx = rd;
}

YsVec3 Obstacle::getPos() {
    return pos;
}

bool Obstacle::getIsVertical() {
    return isVertical;
}

Obstacles::Obstacles(Map& m) : map(m) {
    initObstacles();
}


void Obstacles::initObstacles() {
    srand((unsigned)time(0));
    obstacles.clear();
    auto roads = map.getRoads();
    for (int i = 0; i < roads.size(); i++) {
        int randNum = std::rand() % 100;
        if (randNum > OBSTACLES_PROBABILITY) {
            continue;
        }
        int obstaclePos = std::rand() % 100;
        float pro = obstaclePos / 100.0;
        Road road = roads[i];
        YsVec3 start = road.getRoadStart();
        YsVec3 end = road.getRoadEnd();
        YsVec3 p = start + (end - start) * pro;
        obstacles.push_back(Obstacle(p, road.getIsVertical(), i));
    }
}

void Obstacles::loadObstacleStl(const char* fileName) {
    if (true == LoadBinStl(oneObstacleVtx, oneObstacleNom, fileName)) {
        std::cout << "load obstacle stl successfully" << std::endl;
        int s = obstacles.size();
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < oneObstacleVtx.size() / 3; j++) {
                vtx.push_back(oneObstacleVtx[3*j] + obstacles[i].getPos().xf());
                vtx.push_back(oneObstacleVtx[3*j + 1] + obstacles[i].getPos().yf());
                vtx.push_back(oneObstacleVtx[3*j + 1] + obstacles[i].getPos().zf());
            }
            for (int j = 0; j < oneObstacleVtx.size() / 3; j++) {
                col.push_back(1);
                col.push_back(0.3);
                col.push_back(0.3);
                col.push_back(1);
            }
        }
    } else {
        std::cout << "load obstacle stl fail" << std::endl;
    }
}

void Obstacles::updateCount(YsVec3& pos) {
}

void Obstacles::drawObstacles(YsVec3& pos) {
    updateCount(pos);

    glVertexPointer(3,GL_FLOAT,0,vtx.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
}