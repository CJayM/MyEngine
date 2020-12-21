#include "model.h"

namespace core {

Model::Model()
{
    GLfloat vertices[] = {
        0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,// Top Right
        0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Bottom Left
        -0.5f, 0.5f, 0.0f,  0.0f, 0.0f, 1.0f  // Top Left
    };
    GLuint indices[] = {
        0, 1, 3, // First Triangle
        1, 2, 3 // Second Triangle
    };

    glGenVertexArrays(1, &vertexBuffer);
    glGenBuffers(1, &vbo_);
//    glGenBuffers(1, &ibo_);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
}

Model::~Model()
{
    glDeleteVertexArrays(1, &vertexBuffer);
    glDeleteBuffers(1, &vbo_);
//    glDeleteBuffers(1, &ibo_);

}

void Model::draw()
{
    glBindVertexArray(vertexBuffer);
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}
}
