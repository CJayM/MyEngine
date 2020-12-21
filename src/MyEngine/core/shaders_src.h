#ifndef SHADERS_SRC_H
#define SHADERS_SRC_H

static const char* VERTEX_SHADER_SRC = "#version 330 core\n"
                                       "layout (location = 0) in vec3 vPos;\n"
                                       "layout (location = 1) in vec3 vColor;\n"
                                       "out vec3 ourColor; \n"
                                       "void main()\n"
                                       "{\n"
                                       "gl_Position = vec4(vPos, 1.0);\n"
                                       "ourColor = vColor;\n"
                                       "}\0";

static const char* FRAGMENT_SHADER_SRC = "#version 330 core\n"
                                         "out vec4 fragColor;\n"
                                         "in vec3 ourColor;\n"
                                         "uniform vec4 baseColor;\n"
                                         "void main()\n"
                                         "{\n"
                                         "fragColor = vec4(ourColor ,1.0);\n"
                                         "}\n\0";

#endif // SHADERS_SRC_H
