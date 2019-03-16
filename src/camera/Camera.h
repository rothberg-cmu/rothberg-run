#ifndef ROTHBERG_CAMERA_HEADER
#define ROTHBERG_CAMERA_HEADER

#include "ysclass.h"

class Camera {
public:
    Camera();
    ~Camera();

    YsMatrix4x4 getCameraMat();
    void changeOrientation();
private:
    YsMatrix4x4 cameraMat;
};

#endif