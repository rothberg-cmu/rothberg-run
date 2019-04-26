#include <vector>
#include <algorithm> 
#include "DrawingRoad.h"
#include "../map-generation/Road.h"
#include "binstlTree.h"


// Drawing road (a rectangle actually) from explicitly given road parameters 
void DrawingRoad::drawRoad(YsVec3 start, YsVec3 end, double rW, bool isVertical) {
	rW = rW / 2;
	double extension = 0.0;
	if (start.y() < end.y()) {
		extension = rW;
	} else {
		extension = -rW;
	}
	if (isVertical) {

		vtx.push_back(start.x() + rW);vtx.push_back(start.y() - extension);vtx.push_back(start.z());
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() - extension);vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y() + extension);vtx.push_back(end.z());

		vtx.push_back(start.x() + rW);vtx.push_back(start.y() - extension);vtx.push_back(start.z());
		vtx.push_back(end.x() - rW);vtx.push_back(end.y() + extension);vtx.push_back(end.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() + extension);vtx.push_back(end.z());
	} else {
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() + extension);vtx.push_back(start.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() - extension);vtx.push_back(end.z());
		vtx.push_back(start.x() - rW);vtx.push_back(start.y() - extension);vtx.push_back(start.z());

		vtx.push_back(start.x() - rW);vtx.push_back(start.y() + extension);vtx.push_back(start.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() - extension);vtx.push_back(end.z());
		vtx.push_back(end.x() + rW);vtx.push_back(end.y() + extension);vtx.push_back(end.z());
	}

	// rgb (105,105,105) for gray
	for(int i=0; i<6; ++i){
        col.push_back(0.41f);
        col.push_back(0.41f);
        col.push_back(0.41f);
        col.push_back(0.8f);
    }

	for (int i=0; i<6; ++i) {
		nom.push_back(0);
		nom.push_back(0);
		nom.push_back(1);
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
	LoadCoinBinary(YsVec3::Origin(), 0.004, "../../src/3d-construction/Circle.stl");
	LoadBinary(YsVec3::Origin(), 0.01, "../../src/3d-construction/fence2.stl");
	for (Road road: roads) {
		drawRoad(road);
		//drawTree(road);
		drawTreeSTL(road);
	}
}

void DrawingRoad::drawTree(Road road) {
	YsVec3 start = road.getRoadStart();
	YsVec3 end = road.getRoadEnd();
	double rW = road.getRoadWidth() / 2;
	bool isVertical = road.getIsVertical();

	if (isVertical) {
		double min = std::min(start.y(), end.y()) + TREE_INTERVAL;
		double max = std::max(start.y(), end.y());
		for (double treePos = min; treePos < max; treePos += TREE_INTERVAL) {
			double mid = (start.y() + end.y()) / 2;
			
			vtx.push_back(start.x() - rW);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() - rW - 0.1);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() - rW - 0.1);vtx.push_back(treePos);vtx.push_back(1.0);

			vtx.push_back(start.x() - rW);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() - rW);vtx.push_back(treePos);vtx.push_back(1.0);
			vtx.push_back(start.x() - rW - 0.1);vtx.push_back(treePos);vtx.push_back(1.0);

			// the opposite side
			vtx.push_back(start.x() + rW);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() + rW + 0.1);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() + rW + 0.1);vtx.push_back(treePos);vtx.push_back(1.0);

			vtx.push_back(start.x() + rW);vtx.push_back(treePos);vtx.push_back(0.0);
			vtx.push_back(start.x() + rW);vtx.push_back(treePos);vtx.push_back(1.0);
			vtx.push_back(start.x() + rW + 0.1);vtx.push_back(treePos);vtx.push_back(1.0);

			//saddlebrown rgb(139,69,19)
			for(int i=0; i<12; ++i){
		        col.push_back(0.545f);
		        col.push_back(0.270f);
		        col.push_back(0.074f);
		        col.push_back(0.8f);
		    }
		}

	} else {
		double min = std::min(start.x(), end.x()) + TREE_INTERVAL;
		double max = std::max(start.x(), end.x());
		for (double treePos = min; treePos < max; treePos += TREE_INTERVAL) {
			double mid = (start.x() + end.x()) / 2;
		
			vtx.push_back(treePos);vtx.push_back(start.y() - rW);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(1.0);

			vtx.push_back(treePos);vtx.push_back(start.y() - rW);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() - rW);vtx.push_back(1.0);
			vtx.push_back(treePos);vtx.push_back(start.y() - rW - 0.1);vtx.push_back(1.0);


			// the opposite side
			vtx.push_back(treePos);vtx.push_back(start.y() + rW);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(1.0);

			vtx.push_back(treePos);vtx.push_back(start.y() + rW);vtx.push_back(0.0);
			vtx.push_back(treePos);vtx.push_back(start.y() + rW);vtx.push_back(1.0);
			vtx.push_back(treePos);vtx.push_back(start.y() + rW + 0.1);vtx.push_back(1.0);

			//saddlebrown rgb(139,69,19)
			for(int i=0; i<12; ++i){
		        col.push_back(0.545f);
		        col.push_back(0.270f);
		        col.push_back(0.074f);
		        col.push_back(0.8f);
		    }
		}
	}
}

void DrawingRoad::drawTreeSTL(Road road) {
	YsVec3 start = road.getRoadStart();
	YsVec3 end = road.getRoadEnd();
	double rW = road.getRoadWidth() / 2;
	bool isVertical = road.getIsVertical();

	if (isVertical) {
		double min = std::min(start.y(), end.y()) + TREE_INTERVAL;
		double max = std::max(start.y(), end.y());
		for (double treePos = min; treePos < max; treePos += TREE_INTERVAL) {
			if (road.isInRoad(YsVec3(start.x()- rW * 1.1, treePos, 0))) {
				return;
			}
			LoadBinary(YsVec3(start.x() - rW, treePos, 0), 0.2, "../../src/3d-construction/TreeSTL.stl");
			LoadBinary(YsVec3(start.x() + rW, treePos, 0), 0.2, "../../src/3d-construction/TreeSTL.stl");
		}

	} else {
		double min = std::min(start.x(), end.x()) + TREE_INTERVAL;
		double max = std::max(start.x(), end.x());
		for (double treePos = min; treePos < max; treePos += TREE_INTERVAL) {
			if (road.isInRoad(YsVec3(treePos, start.y() - rW * 1.1, 0))) {
				return;
			}
			LoadBinary(YsVec3(treePos, start.y() - rW, 0), 0.2, "../../src/3d-construction/TreeSTL.stl");
			LoadBinary(YsVec3(treePos, start.y() + rW, 0), 0.2, "../../src/3d-construction/TreeSTL.stl");
		}
	}
}



void DrawingRoad::LoadBinary(YsVec3 offset, double scale, char* stlFileName)
{
    // load binary file for tree stl
	int originalSize = vtx.size();
    if(true==LoadBinStlTree(vtx, nom, stlFileName, offset, scale))
    {
		int addition = vtx.size() - originalSize;

        for(int i=0; i<addition; i+=3)
        {
			if (i < addition * 10 / 17) {
				col.push_back(0);
				col.push_back(1);
				col.push_back(0);
				col.push_back(1);
			} else {
		        col.push_back(0.545f);
		        col.push_back(0.270f);
		        col.push_back(0.074f);
		        col.push_back(0.8f);
			}
        }
    }
}

void DrawingRoad::LoadCoinBinary(YsVec3 offset, double scale, char* stlFileName)
{
    // load binary file for coin stl
	int originalSize = vtx.size();
    if(true==LoadBinStlCoin(vtx, nom, stlFileName, offset, scale))
    {
		int addition = vtx.size() - originalSize;

        for(int i=0; i<addition; i+=3)
        {

			col.push_back(1);
			col.push_back(1);
			col.push_back(0);
			col.push_back(1);

        }
    }
}

std::vector<float> DrawingRoad::getVtx() {
	return vtx;
}
std::vector<float> DrawingRoad::getCol() {
	return col;
}
std::vector<float> DrawingRoad::getNom() {
	return nom;
}