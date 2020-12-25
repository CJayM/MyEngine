#include "camera.h"

namespace core {

Camera::Camera(const Size& size)
    : sceneSize_(size)
{
}

void Camera::update(const Coord2D& mousePos)
{

    if (isDragged_) {
        auto screenPos = window2screen(mousePos);
        auto delta = screenPos - dragStart_;
        pos_.x = oldPos_.x + delta.x;
        pos_.y = oldPos_.y - delta.y / ratio_;
        isMatrixDirty_ = true;
    }
}

void Camera::updateMatrix()
{
    if (isMatrixDirty_ == false)
        return;

    model_.identity();
    model_ = model_.translate(pos_.x, pos_.y, 0);
    model_ = model_.rotateZ(angle_);
    model_ = model_.scale(scale_, scale_);
    matrix_ = projection_ * model_;

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

void Camera::seWindowSize(const Size& pSize)
{
    windowSize_ = pSize;

    auto newRatio_ = windowSize_.getRatio();
    float ratio = sceneSize_.getRatio();
    if (newRatio_ < ratio) {
        viewWidth_ = windowSize_.width * sceneSize_.height/ windowSize_.height;
        viewHeight_ = sceneSize_.height;
    } else {
        viewWidth_ = sceneSize_.width;
        viewHeight_ = windowSize_.height * sceneSize_.width / windowSize_.width;
    }
    //------------
    float halfW = viewWidth_ * 0.5;
    float halfH = viewHeight_ * 0.5;
    projection_ = Matrix::ortho(-halfW, halfW, -halfH, halfH, -100, 100);
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

Coord2D Camera::window2screen(const Coord2D& pos)
{
    Coord2D result = pos;
    result.x *= viewWidth_ / windowSize_.width;
    result.y *= viewHeight_ / windowSize_.height;
    return result;
}

void Camera::startDrag(const Coord2D& mousePos)
{
    dragStart_ = window2screen(mousePos);
    oldPos_ = pos_;
    isDragged_ = true;
}

void Camera::endDrag(const Coord2D& mousePos)
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
