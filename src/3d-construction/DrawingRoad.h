#ifndef ROTHBERG_DRAWROAD_HEADER
#define ROTHBERG_DRAWROAD_HEADER

#include <ysclass.h>
#include <fslazywindow.h>
class DrawingRoad {
public:

	std::vector<float> drawRectangle(YsVec3 start, YsVec3 end, double rW);
};


#endif