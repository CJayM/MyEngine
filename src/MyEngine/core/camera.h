#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include "geom.h"
#include "matrices.h"

namespace core {

class Camera {
public:
    Camera();

    void setPos(float x, float y);
    void setAngle(float angle);
    void setViewSize(float width, float height, float ratio);

    void up(float step);
    void down(float step);
    void left(float step);
    void right(float step);

    void scaleUp(float step);
    void scaleDown(float step);

    Matrix getMatrix();
protected:
    Coord2D pos_ = { 0, 0 };
    float scale_ = 1.0;
    float height = 100;
    float angle_ = 0;

    Matrix model_;
    Matrix perspective_;
    Matrix matrix_;

    float ratio_ = 1.0;
    bool isMatrixDirty_ = true;

    void updateMatrix();
};
}
#endif // CORE_CAMERA_H
