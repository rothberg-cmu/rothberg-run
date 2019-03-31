#ifndef ROTHBERG_CAMERA_HEADER
#define ROTHBERG_CAMERA_HEADER

#include "ysclass.h"
#include "game-player.h"
#include <iostream>

class Camera {
public:
    Camera();
    ~Camera();

    //YsMatrix4x4 getCameraMat();
    static YsMatrix4x4 getCameraMat(GamePlayer player);
    static void changeOrientation(YsMatrix4x4& globalToCamera, int angle);
    void changePosition(YsVec3 pos);
    //void resetMat();
private:
    const static int distance = 10;
    //YsMatrix4x4 cameraMat;
    //int nowAngle = 0;
};

#endif