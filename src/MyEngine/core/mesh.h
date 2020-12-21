#ifndef CORE_MESH_H
#define CORE_MESH_H

#include <array>
#include "core/gl_headers.h"

#include "geom.h"

namespace core {

class Mesh {
public:
    Mesh();
    ~Mesh();

    void draw();
    GLuint vertexBuffer;
private:
    GLuint vbo_;
//    GLuint ibo_;
};

}

#endif // CORE_MESH_H
