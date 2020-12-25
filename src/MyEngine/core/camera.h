#ifndef CORE_CAMERA_H
#define CORE_CAMERA_H

#include "geom.h"
#include "matrices.h"

namespace core {

class Camera {
public:
    Camera(float sceneWidth, float sceneHeight);

    void update(double mouseX, double mouseY);

    void setPos(float x, float y);
    void setAngle(float angle);
    void seWindowSize(float width, float height);

    void up(float step);
    void down(float step);
    void left(float step);
    void right(float step);

    void scaleUp(float step);
    void scaleDown(float step);

    Coord2D window2screen(const Coord2D& pos);
    void startDrag(double x, double y);
    void endDrag(double x, double y);

    Matrix getMatrix();
    Matrix matrix_;
    Matrix model_;
    Matrix projection_;

protected:
    Coord2D pos_ = { 0, 0 };
    Coord2D oldPos_;

    float scale_ = 1.0;
    float height = 100;
    float angle_ = 0;



    float ratio_ = 1.0;
    bool isMatrixDirty_ = true;

    bool isDragged_ = false;
    Coord2D dragStart_;

    float windowWidth_;
    float windowHeight_;

    float sceneWidth_;
    float sceneHeight_;

    float viewWidth_;
    float viewHeight_;

    void updateMatrix();
};
}
#endif // CORE_CAMERA_H
