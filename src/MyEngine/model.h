#ifndef MODEL_H
#define MODEL_H

#include <array>
#include <glad/gl.h>

#include "geom.h"

class Model {
public:
    Model();

    void draw();

    std::array<Vertex, 3> data;
    GLuint glData;
};

#endif // MODEL_H
