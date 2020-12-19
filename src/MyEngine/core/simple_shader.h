#ifndef CORE_SIMPLESHADER_H
#define CORE_SIMPLESHADER_H

#include <glad/gl.h>
#include "matrices.h"

namespace core {

class SimpleShader {
public:
    SimpleShader();

    void setMatrix(const Matrix& matrix);

    GLint vertex_positions;
    GLint vertex_colors;
    GLint cameraMatrix;

    GLuint program;
};

}
#endif // CORE_SIMPLESHADER_H
