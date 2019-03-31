
#include "Camera.h"

Camera::Camera() {
}
Camera::~Camera() {
}
/*
YsMatrix4x4 Camera::getCameraMat() {
    return cameraMat;
}
*/

YsMatrix4x4 Camera::getCameraMat(GamePlayer player) {
    YsMatrix4x4 globalToCamera;
    int angle = player.getAngle();
    YsVec3 pos = player.getPosition();
    changeOrientation(globalToCamera, angle);
    //camera.changePosition(player.getPosition());
    
    globalToCamera.Invert();
    YsMatrix4x4 modelView;  // need #include ysclass.h
    modelView.Translate(0,0,-distance);
    modelView*=globalToCamera;
    modelView.Translate(-pos);
    return modelView;
}

/*
void Camera::resetMat() {
    cameraMat = YsMatrix4x4();
}
*/

void Camera::changeOrientation(YsMatrix4x4& globalToCamera, int angle) {
    if (angle == 0) {
        globalToCamera.RotateYZ(YsPi * 45.0 / 180.0);
        //globalToCamera.RotateYZ(YsPi * 45.0 / 180.0);
    } else if (angle == 180) {
        globalToCamera.RotateYZ(-YsPi * 45.0 / 180.0);
    } else if (angle == 90) {
        globalToCamera.RotateXZ(YsPi * 45.0 / 180.0);
    } else if (angle == 270) {
        globalToCamera.RotateXZ(-YsPi * 45.0 / 180.0);
    }
    globalToCamera.RotateXY(-YsPi * angle / 180.0);
}

void Camera::changePosition(YsVec3 pos) {
    /*
    if (nowAngle == 0) {
        pos.SetY(pos.y() - distance);
    } else if (nowAngle == 90) {
        pos.SetX(pos.x() - distance);
    } else if (nowAngle == 180) {
        pos.SetY(pos.y() + distance);
    } else if (nowAngle == 270) {
        pos.SetX(pos.x() + distance);
    }
    std::cout << pos.Txt() << std::endl;
    */
    //cameraMat.Translate(pos);
}