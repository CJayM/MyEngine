#include "mesh.h"
#include <assert.h>

namespace core {

Mesh::Mesh()
{
    glGenVertexArrays(1, &id);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ibo_);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &id);
    glDeleteBuffers(1, &vbo_);
    //    glDeleteBuffers(1, &ibo_);
}

void Mesh::initGeometry()
{
    auto res = makeGeometry();
    auto points = res.first;
    auto indices = res.second;

    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(id);
    {
        glBindBuffer(GL_ARRAY_BUFFER, vbo_);
        glBufferData(GL_ARRAY_BUFFER, points.size() * sizeof(Vertex3D), &points[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (GLvoid*)(sizeof(Coord3D)));
        glEnableVertexAttribArray(1);
        // UV attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (GLvoid*)(sizeof(Coord3D) + sizeof(Color3f)));
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    }
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO

    isInitialized_ = true;
}

void Mesh::draw(const Camera& camera)
{
    assert(isInitialized_);
    if (material_)
        material_->use(camera);
    glBindVertexArray(id);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::setMaterial(std::shared_ptr<Material> mat)
{
    material_ = mat;
}

std::pair<std::vector<Vertex3D>, std::vector<GLuint>> Mesh::makeGeometry()
{
    const float ratio = 1.0;
    std::vector<Vertex3D> points = {
        { { ratio, 1.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
        { { ratio, -1.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
        { { -ratio, -1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
        { { -ratio, 1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } }
    };
    std::vector<GLuint> indices = {
        0, 1, 3, // First Triangle
        1, 2, 3 // Second Triangle
    };

    return { points, indices };
}
}
