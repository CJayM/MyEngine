#include "camera.h"

namespace core {

Camera::Camera(float sceneWidth, float sceneHeight)
    : sceneWidth_(sceneWidth)
    , sceneHeight_(sceneHeight)
{
}

void Camera::update(double mouseX, double mouseY)
{

    if (isDragged_) {
        auto screenPos = Coord2D(mouseX, mouseY);
        //        screenPos = (matrix_ * screenPos);
        auto delta = screenPos - dragStart_;
        //        delta = matrix_ * delta;
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

void Camera::seWindowSize(float pWidth, float pHeight)
{
    windowWidth_ = pWidth;
    windowHeight_ = pHeight;

    auto newRatio_ = windowWidth_ / windowHeight_;
    float ratio = sceneWidth_ / sceneHeight_;
    if (newRatio_ < ratio) {
        viewWidth_ = windowWidth_ * sceneHeight_ / windowHeight_;
        viewHeight_ = sceneHeight_;
    } else {
        viewWidth_ = sceneWidth_;
        viewHeight_ = windowHeight_ * sceneWidth_ / windowWidth_;
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
