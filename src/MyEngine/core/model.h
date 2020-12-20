#ifndef CORE_MODEL_H
#define CORE_MODEL_H

#include <array>
#include "core/gl_headers.h"

#include "geom.h"

namespace core {

class Model {
public:
    Model();
    ~Model();

    void draw();
    GLuint vertexBuffer;
private:
    GLuint vbo_, ibo_;
};

}

#endif // CORE_MODEL_H
