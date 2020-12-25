#include "matrices.h"
#include <math.h>

namespace core {

Matrix::Matrix()
    : data({ { { 1, 0, 0, 0 },
          { 0, 1, 0, 0 },
          { 0, 0, 1, 0 },
          { 0, 0, 0, 1 } } })
{
}

void Matrix::identity()
{
    data[0] = { 1, 0, 0, 0 };
    data[1] = { 0, 1, 0, 0 };
    data[2] = { 0, 0, 1, 0 };
    data[3] = { 0, 0, 0, 1 };
}

Matrix Matrix::rotateZ(float angle)
{
    float s = sinf(angle);
    float c = cosf(angle);
    Matrix result;
    result.data[0][0] = c;
    result.data[0][1] = s;
    result.data[1][0] = -s;
    result.data[1][1] = c;

    return *this * result;
}

Matrix Matrix::translate(float x, float y, float z)
{
    Matrix result;
    result.data[3][0] = x;
    result.data[3][1] = y;
    result.data[3][2] = z;
    return *this * result;
}

Matrix Matrix::scale(float x, float y)
{
    data[0][0] *= x;
    data[1][1] *= y;
    return *this;
}

Matrix Matrix::invert() const
{
    float s[6];
    float c[6];
    s[0] = data[0][0] * data[1][1] - data[1][0] * data[0][1];
    s[1] = data[0][0] * data[1][2] - data[1][0] * data[0][2];
    s[2] = data[0][0] * data[1][3] - data[1][0] * data[0][3];
    s[3] = data[0][1] * data[1][2] - data[1][1] * data[0][2];
    s[4] = data[0][1] * data[1][3] - data[1][1] * data[0][3];
    s[5] = data[0][2] * data[1][3] - data[1][2] * data[0][3];

    c[0] = data[2][0] * data[3][1] - data[3][0] * data[2][1];
    c[1] = data[2][0] * data[3][2] - data[3][0] * data[2][2];
    c[2] = data[2][0] * data[3][3] - data[3][0] * data[2][3];
    c[3] = data[2][1] * data[3][2] - data[3][1] * data[2][2];
    c[4] = data[2][1] * data[3][3] - data[3][1] * data[2][3];
    c[5] = data[2][2] * data[3][3] - data[3][2] * data[2][3];

    /* Assumes it is invertible */
    float idet = 1.0f / (s[0] * c[5] - s[1] * c[4] + s[2] * c[3] + s[3] * c[2] - s[4] * c[1] + s[5] * c[0]);

    Matrix result;

    result.data[0][0] = (data[1][1] * c[5] - data[1][2] * c[4] + data[1][3] * c[3]) * idet;
    result.data[0][1] = (-data[0][1] * c[5] + data[0][2] * c[4] - data[0][3] * c[3]) * idet;
    result.data[0][2] = (data[3][1] * s[5] - data[3][2] * s[4] + data[3][3] * s[3]) * idet;
    result.data[0][3] = (-data[2][1] * s[5] + data[2][2] * s[4] - data[2][3] * s[3]) * idet;

    result.data[1][0] = (-data[1][0] * c[5] + data[1][2] * c[2] - data[1][3] * c[1]) * idet;
    result.data[1][1] = (data[0][0] * c[5] - data[0][2] * c[2] + data[0][3] * c[1]) * idet;
    result.data[1][2] = (-data[3][0] * s[5] + data[3][2] * s[2] - data[3][3] * s[1]) * idet;
    result.data[1][3] = (data[2][0] * s[5] - data[2][2] * s[2] + data[2][3] * s[1]) * idet;

    result.data[2][0] = (data[1][0] * c[4] - data[1][1] * c[2] + data[1][3] * c[0]) * idet;
    result.data[2][1] = (-data[0][0] * c[4] + data[0][1] * c[2] - data[0][3] * c[0]) * idet;
    result.data[2][2] = (data[3][0] * s[4] - data[3][1] * s[2] + data[3][3] * s[0]) * idet;
    result.data[2][3] = (-data[2][0] * s[4] + data[2][1] * s[2] - data[2][3] * s[0]) * idet;

    result.data[3][0] = (-data[1][0] * c[3] + data[1][1] * c[1] - data[1][2] * c[0]) * idet;
    result.data[3][1] = (data[0][0] * c[3] - data[0][1] * c[1] + data[0][2] * c[0]) * idet;
    result.data[3][2] = (-data[3][0] * s[3] + data[3][1] * s[1] - data[3][2] * s[0]) * idet;
    result.data[3][3] = (data[2][0] * s[3] - data[2][1] * s[1] + data[2][2] * s[0]) * idet;

    return result;
}

Matrix Matrix::ortho(float l, float r, float b, float t, float n, float f)
{
    Matrix M;
    M.data[0][0] = 2.f / (r - l);
    M.data[0][1] = M.data[0][2] = M.data[0][3] = 0.f;

    M.data[1][1] = 2.f / (t - b);
    M.data[1][0] = M.data[1][2] = M.data[1][3] = 0.f;

    M.data[2][2] = -2.f / (f - n);
    M.data[2][0] = M.data[2][1] = M.data[2][3] = 0.f;

    M.data[3][0] = -(r + l) / (r - l);
    M.data[3][1] = -(t + b) / (t - b);
    M.data[3][2] = -(f + n) / (f - n);
    M.data[3][3] = 1.f;

    return M;
}

Coord2D Matrix::operator*(const Coord2D& vec) const
{
    Coord2D result;
    result.x = data[0][0] * vec.x + data[0][1] * vec.y;
    result.y = data[1][0] * vec.x + data[1][1] * vec.y;
    return result;
}

Matrix operator*(Matrix left, const Matrix& right)
{
    Matrix temp;
    int k, r, c;
    for (c = 0; c < 4; ++c)
        for (r = 0; r < 4; ++r) {
            temp.data[c][r] = 0.f;
            for (k = 0; k < 4; ++k)
                temp.data[c][r] += left.data[k][r] * right.data[c][k];
        }
    return temp;
}
}
