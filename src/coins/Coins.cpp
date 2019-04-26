#include "Coins.h"

bool isNearCoin(Coin& coin, YsVec3& pos) {
    return ((coin.getPos() - pos) * (coin.getPos() - pos)) < SURROUNDING_DISTANCE;
}

Coin::Coin(YsVec3 p, int rid, int o) {
    pos = p;
    roadIdx = rid;
    ori = o;
}


YsVec3 Coin::getPos() {
    return pos;
}

int Coin::getRoadIdx() {
    return roadIdx;
}

Coins::Coins(Map& m) : map(m) {
    initCoins();
}

std::vector <float>& Coins::getVtx() {
    return vtx;
}

void Coins::initCoins() {
    auto roads = map.getRoads();
    for (int j = 0; j < roads.size(); j++) {
        Road road = roads[j];
        YsVec3 start = road.getRoadStart();
        YsVec3 end = road.getRoadEnd();
        bool o = road.getIsVertical();
        for (int i = 0; i < COINS_ON_ONE_ROAD; i++) {
            YsVec3 pos = start + (end - start) / ((float) COINS_ON_ONE_ROAD + 1) * ((float) (i + 1));
            Coin coin(pos, j, o);
            coins.push_back(coin);
        }
    }
}

void Coins::updateVtx(YsVec3& pos) {
    int idx = -1;
    for (int i = 0; i < coins.size(); i++) {
        if (isNearCoin(coins[i], pos)) {
            idx = i;
        }
    }
    if (idx == -1) {
        return;
    }

    std::swap(coins[idx], coins[coins.size()-1]);
    coins.pop_back();
    for (int i = 0; i < 4; i++) {
        col.pop_back();
    }
    /*
    for (int i = 0; i < 3; i++) {
        nom.pop_back();
    }
    */
    vtx.clear();
    for (Coin coin : coins) {
        for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
            vtx.push_back(oneCoinVtx[3*i] + coin.getPos().xf());
            vtx.push_back(oneCoinVtx[3*i+1] + coin.getPos().yf());
            vtx.push_back(oneCoinVtx[3*i+2] + coin.getPos().zf());
        }
    }
}

void Coins::loadSTL(char* fileName) {
    if (true == LoadBinStl(oneCoinVtx, oneCoinNom, fileName)) {
        std::cout << "load coin stl successfully" << std::endl;
        for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
            oneCoinCol.push_back(1);
            oneCoinCol.push_back(0.3);
            oneCoinCol.push_back(0.3);
            oneCoinCol.push_back(1);
        }
    } else {
        std::cout << "load coin stl fail" << std::endl;
    }
}

void Coins::drawCoins(YsVec3& pos) {
    updateVtx(pos);
    glVertexPointer(3,GL_FLOAT,0,vtx.data());
    //glNormalPointer(GL_FLOAT,0,stlNom.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
}