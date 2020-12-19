#ifndef CORE_MODEL_H
#define CORE_MODEL_H

#include <array>
#include <glad/gl.h>

#include "geom.h"

namespace core {

class Model {
public:
    Model();

    void draw();

    std::array<Vertex, 3> data;
    GLuint glData;
};

}

#endif // CORE_MODEL_H
