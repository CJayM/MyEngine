#ifndef SIMPLESHADER_H
#define SIMPLESHADER_H

#include <glad/gl.h>
#include <glad/linmath.h>

class SimpleShader {
public:
    SimpleShader();

    void setMatrix(const mat4x4& matrix);

    GLint vertex_positions;
    GLint vertex_colors;
    GLint cameraMatrix;

    GLuint program;
};

#endif // SIMPLESHADER_H
