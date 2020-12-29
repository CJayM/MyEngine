#ifndef CORE_MESH_H
#define CORE_MESH_H

#include <memory>
#include <vector>

#include "core/gl_headers.h"
#include "core/geom.h"

#include "core/material.h"

namespace core {

class Mesh {
public:
    Mesh();
    virtual ~Mesh();

    void initGeometry();
    void draw(const Camera& camera);

    void setMaterial(std::shared_ptr<Material> mat);

    GLuint id;


protected:
    virtual std::pair<std::vector<Vertex3D>, std::vector<GLuint>> makeGeometry();

    GLuint vbo_;
    GLuint ibo_;

    bool isInitialized_ = false;

    std::shared_ptr<Material> material_;
};
}

#endif // CORE_MESH_H
