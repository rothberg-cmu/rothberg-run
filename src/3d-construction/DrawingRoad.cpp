#include <vector>
#include "DrawingRoad.h"
#include "../map-generation/Road.h"


// void DrawingRoad::drawTriangle(std::vector<float> vtx, std::vector<float> col, std::vector<YsVec3> nodes, std::vector<float> rgba) {

// 	for(int i=0; i<nodes.size()/3; ++i){
//         col.push_back(1.0f);
//         col.push_back(0.0f);
//         col.push_back(0.0f);
//         col.push_back(0.1f);
//     }
	
// }

// Drawing road (a rectangle actually) from explicitly given road parameters 
void DrawingRoad::drawRoad(YsVec3 start, YsVec3 end, double rW) {
	vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
	vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());
	vtx.push_back(start.x());vtx.push_back(start.y() - rW);vtx.push_back(start.z());

	vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
	vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());
	vtx.push_back(end.x());vtx.push_back(end.y() + rW);vtx.push_back(end.z());

	for(int i=0; i<6; ++i){
        col.push_back(1.0f);
        col.push_back(0.0f);
        col.push_back(0.0f);
        col.push_back(0.1f);
    }
}

// Drawing road (a rectangle actually) from Road object
void DrawingRoad::drawRoad(Road road) {
	YsVec3 start = road.getRoadStart();
	YsVec3 end = road.getRoadEnd();
	double rW = road.getRoadWidth();
	drawRoad(start, end, rW);
}



std::vector<float> DrawingRoad::getVtx() {
	return vtx;
}
std::vector<float> DrawingRoad::getCol() {
	return col;
}