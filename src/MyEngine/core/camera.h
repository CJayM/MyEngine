#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include "geom.h"
#include "matrices.h"

namespace core {

class Camera {
public:
    Camera();

    void update(double mouseX, double mouseY);

    void setPos(float x, float y);
    void setAngle(float angle);
    void setViewSize(float width, float height);

    void up(float step);
    void down(float step);
    void left(float step);
    void right(float step);

    void scaleUp(float step);
    void scaleDown(float step);

    void startDrag(double x, double y);
    void endDrag(double x, double y);

    Matrix getMatrix();
protected:
    Coord2D pos_ = { 0, 0 };
    Coord2D oldPos_;

    float scale_ = 1.0;
    float height = 100;
    float angle_ = 0;

    Matrix model_;
    Matrix perspective_;
    Matrix matrix_;

    float ratio_ = 1.0;
    bool isMatrixDirty_ = true;

    bool isDragged_ = false;
    Coord2D dragStart_;

    void updateMatrix();
};
}
#endif // CORE_CAMERA_H
