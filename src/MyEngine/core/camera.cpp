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
    model_ = model_.translate(pos_.x, pos_.y);
    model_ = model_.scale(zoom_,  zoom_);
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

void Camera::up(float step)
{
    pos_.y += step;
    isMatrixDirty_ = true;
}

void Camera::down(float step)
{
    pos_.y -= step;
    isMatrixDirty_ = true;
}

void Camera::left(float step)
{
    pos_.x -= step;
    isMatrixDirty_ = true;
}

void Camera::right(float step)
{
    pos_.x += step;
    isMatrixDirty_ = true;
}

void Camera::zoomIn(float step)
{
    zoom_ *= (1+step);
    isMatrixDirty_ = true;
}

void Camera::zoomOut(float step)
{
    zoom_ *= (1-step);
    isMatrixDirty_ = true;
}

Matrix Camera::getMatrix()
{
    if (isMatrixDirty_)
        updateMatrix();

    return matrix_;
}
}
