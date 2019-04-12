#include "Coins.h"

Coin::Coin(YsVec3 p, int rid) {
    pos = p;
    roadIdx = rid;
}

YsVec3 Coin::getPos() {
    return pos;
}

int Coin::getRoadIdx() {
    return roadIdx;
}

Coins::Coins(Map& m) : map(m) {
    initCoins(map.getRoads().size());
}