#include <vector>
#include "DrawingRoad.h"
#include "../map-generation/Road.h"


// Drawing road (a rectangle actually) from explicitly given road parameters 
void DrawingRoad::drawRoad(YsVec3 start, YsVec3 end, double rW, bool isVertical) {
	if (isVertical) {
		vtx.push_back(start.x() + rW);vtx.push_back(start.y() - rW);vtx.push_back(start.z());
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() - rW);vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y() + rW);vtx.push_back(end.z());

		vtx.push_back(start.x() + rW);vtx.push_back(start.y() - rW);vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y() + rW);vtx.push_back(end.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() + rW);vtx.push_back(end.z());
	} else {
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() + rW);vtx.push_back(start.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() - rW);vtx.push_back(end.z());
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() - rW);vtx.push_back(start.z());

		vtx.push_back(start.x() - rW);vtx.push_back(start.y() + rW);vtx.push_back(start.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() - rW);vtx.push_back(end.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() + rW);vtx.push_back(end.z());
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

void DrawingRoad::drawRoad(Map map) {
	std::vector<Road> roads = map.getRoads();
	for (Road road: roads) {
		drawRoad(road);
	}
}

void DrawingRoad::drawTree(Road road) {
	YsVec3 start = road.getRoadStart();
	YsVec3 end = road.getRoadEnd();
	double rW = road.getRoadWidth();
	bool isVertical = road.getIsVertical();

	if (isVertical) {
		double mid = (start.y() + end.y()) / 2;
		
		vtx.push_back(start.x() - rW);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() - rW - 0.1);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() - rW - 0.1);vtx.push_back(mid);vtx.push_back(1.0);

		vtx.push_back(start.x() - rW);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() - rW);vtx.push_back(mid);vtx.push_back(1.0);
		vtx.push_back(start.x() - rW - 0.1);vtx.push_back(mid);vtx.push_back(1.0);


		// the opposite side
		vtx.push_back(start.x() + rW);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() + rW + 0.1);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() + rW + 0.1);vtx.push_back(mid);vtx.push_back(1.0);

		vtx.push_back(start.x() + rW);vtx.push_back(mid);vtx.push_back(0.0);
		vtx.push_back(start.x() + rW);vtx.push_back(mid);vtx.push_back(1.0);
		vtx.push_back(start.x() + rW + 0.1);vtx.push_back(mid);vtx.push_back(1.0);
	} else {
		double mid = (start.x() + end.x()) / 2;
		
		vtx.push_back(mid);vtx.push_back(start.y() - rW);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(1.0);

		vtx.push_back(mid);vtx.push_back(start.y() - rW);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() - rW);vtx.push_back(1.0);
		vtx.push_back(mid);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(1.0);


		// the opposite side
		vtx.push_back(mid);vtx.push_back(start.y() + rW);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(1.0);

		vtx.push_back(mid);vtx.push_back(start.y() + rW);vtx.push_back(0.0);
		vtx.push_back(mid);vtx.push_back(start.y() + rW);vtx.push_back(1.0);
		vtx.push_back(mid);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(1.0);
	}

	//saddlebrown rgb(139,69,19)
	for(int i=0; i<12; ++i){
        col.push_back(0.545f);
        col.push_back(0.270f);
        col.push_back(0.074f);
        col.push_back(0.8f);
    }
	
}

std::vector<float> DrawingRoad::getVtx() {
	return vtx;
}
std::vector<float> DrawingRoad::getCol() {
	return col;
}