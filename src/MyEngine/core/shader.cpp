#include "shader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "geom.h"

namespace core {

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);

        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << vertexPath << " or " << fragmentPath << std::endl;
        return;
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vShaderCode, nullptr);
    glCompileShader(vertex_shader);
    checkCompileErrors(vertex_shader, "VERTEX");

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fShaderCode, NULL);
    glCompileShader(fragment_shader);
    checkCompileErrors(fragment_shader, "FRAGMENT");

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    checkCompileErrors(program, "PROGRAM");

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    cameraMatrix = glGetUniformLocation(program, "MVP");
    vertex_positions = glGetAttribLocation(program, "vPos");
    vertex_colors = glGetAttribLocation(program, "vCol");
    baseColor = glGetUniformLocation(program, "baseColor");

    glEnableVertexAttribArray(vertex_positions);
    glVertexAttribPointer(vertex_positions, 2, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)(0));
    glEnableVertexAttribArray(vertex_colors);
    glVertexAttribPointer(vertex_colors, 3, GL_FLOAT, GL_FALSE,
        sizeof(Vertex), (void*)(sizeof(Coord2D)));
}

void Shader::use()
{
    glUseProgram(program);
}

void Shader::setMatrix(const Matrix& matrix)
{
    glUniformMatrix4fv(cameraMatrix, 1, GL_FALSE, (const GLfloat*)&matrix.data[0]);
}

void Shader::setBaseColor(Color3f color)
{
    glUniform3f(baseColor, color.r,color.g,color.b);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                      << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                      << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}
}
