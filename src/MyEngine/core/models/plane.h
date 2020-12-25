#ifndef CORE_MODELS_PLANE_H
#define CORE_MODELS_PLANE_H

#include "core/mesh.h"

namespace core {
namespace models {

    class Plane : public Mesh {
    public:
        Plane(const Size& size);
        virtual ~Plane();

        Size size;

        // Mesh interface
    protected:
        std::pair<std::vector<Vertex3D>, std::vector<GLuint>> makeGeometry();
    };
}
}

#endif
