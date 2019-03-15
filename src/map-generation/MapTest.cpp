#include <iostream>
#include "Map.h"

int main() {
    std::cout << "here is test" << std::endl;
    Map map;
    map.dbgPrintRoads();
    std::cout << map.isInMap(0, 300, 10) << std::endl;
    return 0;
}