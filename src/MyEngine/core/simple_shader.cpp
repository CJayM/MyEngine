#include "simple_shader.h"

#include <iostream>

#include "geom.h"
#include "shaders_src.h"

namespace core {

SimpleShader::SimpleShader()
{
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &VERTEX_SHADER_SRC, NULL);
    glCompileShader(vertex_shader);

    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &FRAGMENT_SHADER_SRC, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    // Check for linking errors
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
    }
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    cameraMatrix = glGetUniformLocation(program, "MVP");
    vertex_positions = glGetAttribLocation(program, "vPos");
    vertex_colors = glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vertex_positions);
    glVertexAttribPointer(vertex_positions, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)(0));
    glEnableVertexAttribArray(vertex_colors);
    glVertexAttribPointer(vertex_colors, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)(sizeof(Coord2D)));
}

void SimpleShader::setMatrix(const Matrix& matrix)
{
    glUniformMatrix4fv(cameraMatrix, 1, GL_FALSE, (const GLfloat*)&matrix.data[0]);
}
}
