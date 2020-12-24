#include "camera.h"

namespace core {

Camera::Camera()
{
}

void Camera::update(double mouseX, double mouseY)
{

    if (isDragged_){
        auto delta = Coord2D(mouseX, mouseY) - dragStart_;
        pos_.x = oldPos_.x + delta.x ;
        pos_.y = oldPos_.y - delta.y /      ratio_;
        isMatrixDirty_ = true;
//        fprintf(stdout, "Drag: %fx%f\n", mouseX, mouseY);
        fprintf(stdout, "Drag: %fx%f\n", delta.x, delta.y);
        fflush(stdout);
    }
}

void Camera::updateMatrix()
{
    if (isMatrixDirty_ == false)
        return;

    model_.identity();
    model_ = model_.translate(pos_.x, pos_.y, 0);
    model_ = model_.scale(scale_, scale_);
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

void Camera::setViewSize(float width, float height)
{
    float halfW = width * 0.5 ;
    float halfH = height * 0.5;
    perspective_ = Matrix::ortho(-halfW, halfW, -halfH, halfH, -100, 100);
    isMatrixDirty_ = true;
}

void Camera::up(float step)
{
    pos_.y -= step;
    isMatrixDirty_ = true;
}

void Camera::down(float step)
{
    pos_.y += step;
    isMatrixDirty_ = true;
}

void Camera::left(float step)
{
    pos_.x += step;
    isMatrixDirty_ = true;
}

void Camera::right(float step)
{
    pos_.x -= step;
    isMatrixDirty_ = true;
}

void Camera::scaleUp(float step)
{
    scale_ *= (1 + step);
    isMatrixDirty_ = true;

    fprintf(stdout, "Scale: %f\n", scale_);
    fflush(stdout);
}

void Camera::scaleDown(float step)
{
    scale_ *= (1 - step);
    isMatrixDirty_ = true;

    fprintf(stdout, "Scale: %f\n", scale_);
    fflush(stdout);
}

void Camera::startDrag(double x, double y)
{
    dragStart_.x = x;
    dragStart_.y = y;

    fprintf(stdout, "Drag START: %fx%f\n", x, y);
    fflush(stdout);

    oldPos_ = pos_;

    isDragged_ = true;
}

void Camera::endDrag(double x, double y)
{
    isDragged_ = false;
}

Matrix Camera::getMatrix()
{
    if (isMatrixDirty_)
        updateMatrix();

    return matrix_;
}
}
