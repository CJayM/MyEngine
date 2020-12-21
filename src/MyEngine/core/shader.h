#ifndef CORE_SIMPLESHADER_H
#define CORE_SIMPLESHADER_H

#include "core/gl_headers.h"
#include "geom.h"
#include "matrices.h"

namespace core {

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    void use();

    void setMatrix(const Matrix& matrix);
    void setBaseColor(Color3f color);

    GLint vertex_positions;
    GLint vertex_colors;
    GLint cameraMatrix;
    GLint baseColor;

    GLuint program;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
}
#endif // CORE_SIMPLESHADER_H
