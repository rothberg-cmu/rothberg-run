#ifndef ROTHBERG_CAMERA_HEADER
#define ROTHBERG_CAMERA_HEADER

#include "ysclass.h"

class Camera {
public:
    Camera();
    ~Camera();

    YsMatrix4x4 getCameraMat();
    void changeOrientation(int angle);
    void changePosition(YsVec3 pos);
    void resetMat();
private:
    const int distance = 10;
    YsMatrix4x4 cameraMat;
    int nowAngle = 0;
};

#endif