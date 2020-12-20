#ifndef SHADERS_SRC_H
#define SHADERS_SRC_H

static const char* VERTEX_SHADER_SRC = "#version 330 core\n"
                                       "layout (location = 0) in vec3 position;\n"
                                       "void main()\n"
                                       "{\n"
                                       "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
                                       "}\0";

static const char* FRAGMENT_SHADER_SRC = "#version 330 core\n"
                                         "out vec4 color;\n"
                                         "void main()\n"
                                         "{\n"
                                         "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                         "}\n\0";

#endif // SHADERS_SRC_H
