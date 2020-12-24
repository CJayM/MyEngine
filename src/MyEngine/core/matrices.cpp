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
    data[3][0] = x;
    data[3][1] = y;
    data[3][2] = z;
    return *this;
}

Matrix Matrix::scale(float x, float y)
{
    data[0][0] *= x;
    data[1][1] *= y;
    return *this;
}

Matrix Matrix::ortho(float l, float r, float b, float t, float n, float f)
{
    Matrix M;
    M.data[0][0] = 2.f/(r-l);
    M.data[0][1] = M.data[0][2] = M.data[0][3] = 0.f;

    M.data[1][1] = 2.f/(t-b);
    M.data[1][0] = M.data[1][2] = M.data[1][3] = 0.f;

    M.data[2][2] = -2.f/(f-n);
    M.data[2][0] = M.data[2][1] = M.data[2][3] = 0.f;

    M.data[3][0] = -(r+l)/(r-l);
    M.data[3][1] = -(t+b)/(t-b);
    M.data[3][2] = -(f+n)/(f-n);
    M.data[3][3] = 1.f;

    return M;
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
