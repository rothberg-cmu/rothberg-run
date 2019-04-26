#include "ysclass.h"
#include <vector>
#include "Map.h"
#include "binstl.h"
#include <iostream>
#include "fslazywindow.h"

#define SURROUNDING_DISTANCE 0.3
#define COINS_ON_ONE_ROAD 3
#define COINS_SIZE_SCALE 0.08

class Coin {
public:
    int roadIdx = -1;
    YsVec3 pos;
    int ori = -1; // 0 denotes horionzontal and 1 denotes verticle road 
public:
    Coin(YsVec3 p, int rid, int o);
    YsVec3 getPos();
    int getRoadIdx();
    int getOrientation();
    //void addSelfToDrawingVector(std::vector <float>& vtx, std::vector <float>& col, std::vector <float>& nom);
};

class Coins {
private:
    void initCoins();
    Map& map;
    int initScore = 0;
    std::vector <float> vtx;
    std::vector <float> col;
    std::vector <float> nom;
    std::vector <float> oneCoinVtx;
    std::vector <float> oneCoinCol;
    std::vector <float> oneCoinNom;
    void updateVtx(YsVec3& pos);
public:
    Coins();
    Coins(int n);
    Coins(Map& m);
    void restartCoins();
    std::vector <Coin> coins;
    std::vector <float> & getVtx();
    void drawCoins(YsVec3& pos);
    void loadSTL(const char* fileName);
    int getScore();
};