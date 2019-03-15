#include <vector>
#include "DrawingRoad.h"

//DrawingRoad::DrawingRoad(){}

// void DrawingRoad::drawTriangle(std::vector<float> vtx, std::vector<float> col, std::vector<YsVec3> nodes, std::vector<float> rgba) {

// 	for(int i=0; i<nodes.size()/3; ++i){
//         col.push_back(1.0f);
//         col.push_back(0.0f);
//         col.push_back(0.0f);
//         col.push_back(0.1f);
//     }
	
// }


// void DrawingRoad::drawRoad(Road road) {

// }

std::vector<float> DrawingRoad::drawRectangle(YsVec3 start, YsVec3 end, double rW) {
	std::vector<float> vtx;
	vtx.push_back(start.x());vtx.push_back(start.y() - rW);vtx.push_back(start.z());
	vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
	vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());

	vtx.push_back(start.x());vtx.push_back(start.y() + rW);vtx.push_back(start.z());
	vtx.push_back(end.x());vtx.push_back(end.y() - rW);vtx.push_back(end.z());
	vtx.push_back(end.x());vtx.push_back(end.y() + rW);vtx.push_back(end.z());

    return vtx;
}
