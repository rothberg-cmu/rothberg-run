#ifndef ROTHBERG_DRAWROAD_HEADER
#define ROTHBERG_DRAWROAD_HEADER

#include <ysclass.h>
#include <fslazywindow.h>
#include "../map-generation/Road.h"
class DrawingRoad {
private:
	std::vector<float> vtx;
	std::vector<float> col;

public:
	DrawingRoad(){};

	void drawRoad(YsVec3 start, YsVec3 end, double rW, bool isVertical);
	void drawRoad(Road road);

	std::vector<float> getVtx();
	std::vector<float> getCol();
};


#endif