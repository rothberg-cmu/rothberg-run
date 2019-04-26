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
    coins.clear();
    auto roads = map.getRoads();
    std::cout << "begin init coins" << std::endl;
    for (int j = 0; j < roads.size(); j++) {
        Road road = roads[j];
        YsVec3 start = road.getRoadStart();
        YsVec3 end = road.getRoadEnd();
        std::cout << "road begin " << start.Txt() << std::endl;
        std::cout << "road end " << end.Txt() << std::endl;
        bool o = road.getIsVertical();
        for (int i = 0; i < COINS_ON_ONE_ROAD; i++) {
            YsVec3 pos = start + (end - start) / ((float) COINS_ON_ONE_ROAD + 1) * ((float) (i + 1));
            Coin coin(pos, j, o);
            std::cout << "coin pos " << pos.Txt() << std::endl;
            coins.push_back(coin);
        }
        std::cout << "-------------" << std::endl;
    }
    initScore = coins.size();
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

void Coins::loadSTL(const char* fileName) {
    if (true == LoadBinStl(oneCoinVtx, oneCoinNom, fileName)) {
        std::cout << "load coin stl successfully" << std::endl;
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
        for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
            x += oneCoinVtx[3*i];
            y += oneCoinVtx[3*i+1];
            z += oneCoinVtx[3*i+2];
        }
        x /= oneCoinVtx.size() / 3;
        y /= oneCoinVtx.size() / 3;
        z /= oneCoinVtx.size() / 3;
        std::cout << "x = " << x << " y = " << y << " z = " << z << std::endl;
        for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
            oneCoinVtx[3*i] = (oneCoinVtx[3*i] - x) * COINS_SIZE_SCALE;
            oneCoinVtx[3*i+1] = (oneCoinVtx[3*i+1] - y) * COINS_SIZE_SCALE;
            oneCoinVtx[3*i+2] = (oneCoinVtx[3*i+2] - z) * COINS_SIZE_SCALE + COINS_SIZE_SCALE;
        }
        for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
            oneCoinCol.push_back(1);
            oneCoinCol.push_back(0.3);
            oneCoinCol.push_back(0.3);
            oneCoinCol.push_back(1);
        }
        for (Coin coin : coins) {
            std::cout << coin.getPos().Txt() << std::endl;
            for (int i = 0; i < oneCoinVtx.size() / 3; i++) {
                vtx.push_back(oneCoinVtx[3*i] + coin.getPos().xf());
                vtx.push_back(oneCoinVtx[3*i+1] + coin.getPos().yf());
                vtx.push_back(oneCoinVtx[3*i+2] + coin.getPos().zf());
            }
            for (int i = 0; i < oneCoinCol.size() / 4; i++) {
                col.push_back(1);
                col.push_back(0.3);
                col.push_back(0.3);
                col.push_back(1);
            }
        }
    } else {
        std::cout << "load coin stl fail" << std::endl;
    }
}

void Coins::restartCoins() {
    initCoins();
}

int Coins::getScore() {
    return initScore - coins.size();
}

void Coins::drawCoins(YsVec3& pos) {
    updateVtx(pos);
    //std::cout << "player pos " << pos.Txt() << std::endl;
    //std::cout << vtx.size() << std::endl;
    //std::cout << col.size() << std::endl;
    glVertexPointer(3,GL_FLOAT,0,vtx.data());
    //glNormalPointer(GL_FLOAT,0,stlNom.data());
    glColorPointer(4,GL_FLOAT,0,col.data());
    glDrawArrays(GL_TRIANGLES,0,vtx.size()/3);
}