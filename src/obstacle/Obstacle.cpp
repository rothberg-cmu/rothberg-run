
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

void Obstacles::restart() {
    count = 0;
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
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
        for (int i = 0; i < oneObstacleVtx.size() / 3; i++) {
            x += oneObstacleVtx[3*i];
            y += oneObstacleVtx[3*i+1];
            z += oneObstacleVtx[3*i+2];
        }
        x /= oneObstacleVtx.size() / 3;
        y /= oneObstacleVtx.size() / 3;
        z /= oneObstacleVtx.size() / 3;
        for (int i = 0; i < oneObstacleVtx.size() / 3; i++) {
            oneObstacleVtx[3 * i] = (oneObstacleVtx[3*i] - x) / OBSTACLES_X_SCALE;
            oneObstacleVtx[3 * i + 1] = (oneObstacleVtx[3*i + 1] - y) / OBSTACLES_Y_SCALE;
            oneObstacleVtx[3 * i + 2] = (oneObstacleVtx[3*i + 2] - 0) / OBSTACLES_Z_SCALE;
        }
        int s = obstacles.size();
        for (int i = 0; i < s; i++) {
            bool v = obstacles[i].getIsVertical();
            float xa = obstacles[i].getPos().xf();
            float ya = obstacles[i].getPos().yf();
            float za = obstacles[i].getPos().zf();
            for (int j = 0; j < oneObstacleVtx.size() / 3; j++) {
                /*
                vtx.push_back((v ? oneObstacleVtx[3*j] : oneObstacleVtx[3*j+1]) + xa);
                vtx.push_back((v ? oneObstacleVtx[3*j+1] : oneObstacleVtx[3*j]) + ya);
                */
                float xtmp = oneObstacleVtx[3*j];
                float ytmp = oneObstacleVtx[3*j+1];
                if (!v) {
                    float tmp = xtmp;
                    xtmp = ytmp;
                    ytmp = tmp;
                }
                vtx.push_back(xtmp + xa);
                vtx.push_back(ytmp + ya);
                vtx.push_back(oneObstacleVtx[3*j+2] + za);
            }
            for (int j = 0; j < oneObstacleVtx.size() / 3; j++) {
                col.push_back(0);
                col.push_back(0);
                col.push_back(1);
                col.push_back(1);
            }
        }
    } else {
        std::cout << "load obstacle stl fail" << std::endl;
    }
}

float getDis(float x, float y, float xa, float ya) {
    return std::sqrt((x - xa) * (x - xa) + (y - ya) * (y - ya));
}

void Obstacles::updateCount(YsVec3& pos) {
    float x = pos.xf();
    float y = pos.yf();
    float z = pos.zf();
    for (int i = 0; i < obstacles.size(); i++) {
        Obstacle obj = obstacles[i];
        float ox = obj.getPos().xf();
        float oy = obj.getPos().yf();
        float oz = obj.getPos().zf();
        if (getDis(x, y, ox, oy) < OBSTACLES_MIN_DIS) {
            if (z < 0.5 && i != prevObjIdx) {
                std::cout << "obstacle!!!!!!!!!" << std::endl;
                prevObjIdx = i;
                count++;
            }
        }
        /*
        bool v = obj.getIsVertical();
        bool flag = false;
        if (v) {
            if (std::abs(ox - x) < OBSTACLES_MIN_DIS) {
                flag = true;
            }
        } else {
            if (std::abs(oy - y) < OBSTACLES_MIN_DIS) {
                flag = true;
            }
        }
        if (flag) {
            std::cout << "obstacle!!!!!!!!!" << std::endl;
            count--;
        }
        */
    }
}

int Obstacles::drawObstacles(YsVec3& pos) {
    updateCount(pos);

    glVertexPointer(3,GL_FLOAT,0,vtx.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
    return count;
}