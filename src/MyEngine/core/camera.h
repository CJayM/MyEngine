#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include "geom.h"
#include "matrices.h"

namespace core {

class Camera {
public:
    Camera(const Size& size);

    void update(const Coord2D& mousePos);

    void setPos(float x, float y);
    void setAngle(float angle);
    void seWindowSize(const Size& size);

    void up(float step);
    void down(float step);
    void left(float step);
    void right(float step);

    void resetScale(float value);
    void scaleUp(float step);
    void scaleDown(float step);

    Coord2D window2screen(const Coord2D& pos);
    void startDrag(const Coord2D& mousePos);
    void endDrag(const Coord2D& mousePos);

    Matrix getMatrix();
    Matrix matrix_;
    Matrix model_;
    Matrix projection_;

protected:
    Coord2D pos_ = { 0, 0 };
    Coord2D oldPos_;

    float scale_ = 1.0;
    float angle_ = 0;

    float ratio_ = 1.0;
    bool isMatrixDirty_ = true;

    bool isDragged_ = false;
    Coord2D dragStart_;

    Size windowSize_;
    Size sceneSize_;

    float viewWidth_;
    float viewHeight_;

    void updateMatrix();
};
}
#endif // CORE_CAMERA_H
