#include "model.h"

namespace core {

Model::Model()
{
    data[0] = { -0.6f, -0.4f, 1.f, 0.f, 0.f };
    data[1] = { 0.6f, -0.4f, 0.f, 1.f, 0.f };
    data[2] = { 0.f, 0.6f, 0.f, 0.f, 1.f };

    glGenBuffers(1, &glData);
    glBindBuffer(GL_ARRAY_BUFFER, glData);
}

void Model::draw()
{
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), &data[0], GL_STATIC_DRAW);
    glDrawArrays(GL_TRIANGLES, 0, data.size());
}
}
