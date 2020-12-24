#ifndef CORE_MATRICES_H
#define CORE_MATRICES_H

#include <array>

namespace core {

struct Matrix {
    Matrix();
    std::array<std::array<float, 4>, 4> data;

    void identity();
    Matrix rotateZ(float angle);
    Matrix translate(float x, float y, float z=1.0);
    Matrix scale(float x, float y);
    static Matrix ortho(float l, float r, float b, float t, float n, float f);

};


Matrix operator*(Matrix left, const Matrix& right);

}

#endif // CORE_MATRICES_H
