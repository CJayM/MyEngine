#ifndef SHADERS_SRC_H
#define SHADERS_SRC_H

static const char* VERTEX_SHADER_SRC = "#version 110\n"
                                       "uniform mat4 MVP;\n"
                                       "attribute vec3 vCol;\n"
                                       "attribute vec2 vPos;\n"
                                       "varying vec3 color;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
                                       "    color = vCol;\n"
                                       "}\n";

static const char* FRAGMENT_SHADER_SRC = "#version 110\n"
                                         "varying vec3 color;\n"
                                         "void main()\n"
                                         "{\n"
                                         "    gl_FragColor = vec4(color, 1.0);\n"
                                         "}\n";

#endif // SHADERS_SRC_H
