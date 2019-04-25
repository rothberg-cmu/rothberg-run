#include "Coins.h"

bool isNearCoin(Coin& coin, YsVec3& pos) {
    return ((coin.getPos() - pos) * (coin.getPos() - pos)) < SURROUNDING_DISTANCE;
}

Coin::Coin(YsVec3 p, int rid, int o) {
    pos = p;
    roadIdx = rid;
    ori = o;
}

void Coin::addSelfToDrawingVector(std::vector <float>& vtx, std::vector <float>& col, std::vector <float>& nom) {

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
    vtx.clear();
    col.clear();
    for (Coin coin : coins) {
        vtx.push_back(coin.getPos().xf());
        vtx.push_back(coin.getPos().yf());
        vtx.push_back(coin.getPos().zf());
    }
}