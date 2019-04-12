#ifndef ROTHBERG_DRAWROAD_HEADER
#define ROTHBERG_DRAWROAD_HEADER

#include <ysclass.h>
#include <fslazywindow.h>
#include "../map-generation/Road.h"
#include "../map-generation/Map.h"

#define TREE_INTERVAL 5.0

class DrawingRoad {
private:
	std::vector<float> vtx;
	std::vector<float> col;
	std::vector <float> nom;

    YsVec3 position;
	YsVec3 viewTarget;
    YsMatrix4x4 viewRot;
    double viewDistance;
    double nearZ,farZ;

public:
	DrawingRoad(){};

	void drawRoad(YsVec3 start, YsVec3 end, double rW, bool isVertical);
	void drawRoad(Road road);
	void drawRoad(Map map);
	void drawTree(Road road);
	void drawTreeSTL(Road road);

	void LoadBinary(YsVec3 offset, double scale, char* stlFileName);
	void LoadCoinBinary(YsVec3 offset, double scale, char* stlFileName);


	std::vector<float> getVtx();
	std::vector<float> getCol();
	std::vector<float> getNom();
};


#endif