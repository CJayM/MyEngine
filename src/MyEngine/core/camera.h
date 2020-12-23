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
    void setRatio(float ratio);
    Matrix getMatrix();
protected:
    Coord2D pos_ = { 0, 0 };
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
