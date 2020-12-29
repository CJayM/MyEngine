#ifndef CORE_MESH_H
#define CORE_MESH_H

#include <memory>
#include <vector>

#include "core/gl_headers.h"
#include "core/geom.h"

#include "core/material.h"
#include "core/idrawable.h"

namespace core {

class Mesh: IDrawable {
public:
    Mesh();
    virtual ~Mesh();

    void initGeometry();
    void draw(const Camera& camera) override;

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
