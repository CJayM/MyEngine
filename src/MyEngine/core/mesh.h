#ifndef CORE_MESH_H
#define CORE_MESH_H

#include <memory>
#include <vector>

#include "core/gl_headers.h"
#include "core/geom.h"

namespace core {

class Mesh {
public:
    Mesh();
    virtual ~Mesh();

    void initGeometry();
    void draw();
    GLuint id;

protected:
    virtual std::pair<std::vector<Vertex3D>, std::vector<GLuint>> makeGeometry();

    GLuint vbo_;
    GLuint ibo_;
};
}

#endif // CORE_MESH_H
