#include "simple_shader.h"

#include "geom.h"
#include "shaders_src.h"

SimpleShader::SimpleShader()
{
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &VERTEX_SHADER_SRC, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &FRAGMENT_SHADER_SRC, NULL);
    glCompileShader(fragment_shader);

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    glLinkProgram(program);

    cameraMatrix = glGetUniformLocation(program, "MVP");
    vertex_positions = glGetAttribLocation(program, "vPos");
    vertex_colors = glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vertex_positions);
    glVertexAttribPointer(vertex_positions, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(vertex_colors);
    glVertexAttribPointer(vertex_colors, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)(sizeof(float) * 2));
}

void SimpleShader::setMatrix(const mat4x4& matrix)
{
    glUniformMatrix4fv(cameraMatrix, 1, GL_FALSE, (const GLfloat*)matrix);
}
