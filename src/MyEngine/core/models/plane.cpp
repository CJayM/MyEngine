#include "plane.h"

namespace core {
namespace models {

    Plane::Plane(float pWidth, float pHeight)
        : Mesh()
        , width(pWidth)
        , height(pHeight)
    {
    }

    Plane::~Plane()
    {
    }

    std::pair<std::vector<core::Vertex3D>, std::vector<GLuint>> core::models::Plane::makeGeometry()
    {
        float w2 = width * 0.5;
        float h2 = width * 0.5;
        std::vector<Vertex3D> points = {
            { { w2, h2, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
            { { w2, -h2, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
            { { -w2, -h2, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
            { { -w2, h2, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } }
        };
        std::vector<GLuint> indices = {
            0, 1, 3, // First Triangle
            1, 2, 3 // Second Triangle
        };

        return { points, indices };
    }
}
}
