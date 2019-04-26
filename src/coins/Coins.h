#include "ysclass.h"
#include <vector>
#include "Map.h"

class Coin{
public:
    int roadIdx = -1;
    YsVec3 pos;

public:
    Coin(YsVec3 p, int rid);
    YsVec3 getPos();
    int getRoadIdx();
};

class Coins {
private:
    void initCoins(int num);
    Map& map;
public:
    Coins();
    Coins(int n);
    Coins(Map& m);
    std::vector <Coin> coins;
};