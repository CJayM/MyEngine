#ifndef CORE_MESH_H
#define CORE_MESH_H

#include "core/gl_headers.h"
#include <array>

#include "geom.h"

namespace core {

class Mesh {
public:
    Mesh();
    ~Mesh();

    void draw();
    GLuint id;

private:
    GLuint vbo_;
    GLuint ibo_;
};
}

#endif // CORE_MESH_H
