#include <vector>
#include "DrawingRoad.h"
#include "../map-generation/Road.h"


// Drawing road (a rectangle actually) from explicitly given road parameters 
void DrawingRoad::drawRoad(YsVec3 start, YsVec3 end, double rW, bool isVertical) {
	if (isVertical) {
		vtx.push_back(start.x() + rW);vtx.push_back(start.y());vtx.push_back(start.z());
		vtx.push_back(start.x() - rW);vtx.push_back(start.y());vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y());vtx.push_back(end.z());

		vtx.push_back(start.x() + rW);vtx.push_back(start.y());vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y());vtx.push_back(end.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y());vtx.push_back(end.z());
	} else {
		vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
		vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());
		vtx.push_back(start.x());vtx.push_back(start.y() - rW);vtx.push_back(start.z());

		vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
		vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());
		vtx.push_back(end.x());vtx.push_back(end.y() + rW);vtx.push_back(end.z());
	}

	// rgb (105,105,105) for gray
	for(int i=0; i<6; ++i){
        col.push_back(0.41f);
        col.push_back(0.41f);
        col.push_back(0.41f);
        col.push_back(0.8f);
    }
}

// Drawing road (a rectangle actually) from Road object
void DrawingRoad::drawRoad(Road road) {
	YsVec3 start = road.getRoadStart();
	YsVec3 end = road.getRoadEnd();
	double rW = road.getRoadWidth();
	bool isVertical = road.getIsVertical();
	drawRoad(start, end, rW, isVertical);
}


std::vector<float> DrawingRoad::getVtx() {
	return vtx;
}
std::vector<float> DrawingRoad::getCol() {
	return col;
}