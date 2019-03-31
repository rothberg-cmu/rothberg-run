
#include "Camera.h"

Camera::Camera() {
}
Camera::~Camera() {
}
YsMatrix4x4 Camera::getCameraMat() {
    return cameraMat;
}

void Camera::resetMat() {
    cameraMat = YsMatrix4x4();
}

void Camera::changeOrientation(int angle) {
    nowAngle = angle;
    cameraMat.RotateXY(angle);
}

void Camera::changePosition(YsVec3 pos) {
    if (nowAngle == 0) {
        pos.SetY(pos.y() - distance);
    } else if (nowAngle == 90) {
        pos.SetX(pos.x() - distance);
    } else if (nowAngle == 180) {
        pos.SetY(pos.y() + distance);
    } else if (nowAngle == 270) {
        pos.SetX(pos.x() + distance);
    }
    cameraMat.Translate(pos);
}