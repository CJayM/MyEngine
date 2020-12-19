#include "camera.h"

namespace core {

Camera::Camera()
{
}

void Camera::updateMatrix()
{    
    if (isMatrixDirty_ == false)
        return;

    model_.identity();
    model_ = model_.rotateZ(angle_);
    matrix_ = perspective_ * model_;

    isMatrixDirty_ = false;
}

void Camera::setPos(float x, float y)
{
    if ((pos_.x == x) && (pos_.y == y))
        return;

    isMatrixDirty_ = true;

    pos_.x = x;
    pos_.y = y;
}

void Camera::setAngle(float angle)
{
    if (angle == angle_)
        return;

    isMatrixDirty_ = true;
    angle_ = angle;
}

void Camera::setRatio(float ratio)
{
    if (ratio == ratio_)
        return;

    isMatrixDirty_ = true;
    ratio_ = ratio;
    perspective_ = Matrix::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
}

Matrix Camera::getMatrix()
{
    if (isMatrixDirty_)
        updateMatrix();

    return matrix_;
}
}
