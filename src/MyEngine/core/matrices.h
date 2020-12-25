#ifndef CORE_MATRICES_H
#define CORE_MATRICES_H

#include "core/geom.h"
#include <array>

namespace core {

struct Matrix {
    Matrix();
    static Matrix ortho(float l, float r, float b, float t, float n, float f);


    void identity();
    Matrix rotateZ(float angle);
    Matrix translate(float x, float y, float z);
    Matrix scale(float x, float y);
    Matrix invert() const;

    Coord2D operator*(const Coord2D& vec) const;

    std::array<std::array<float, 4>, 4> data;
};


Matrix operator*(Matrix left, const Matrix& right);


}

#endif // CORE_MATRICES_H
