#include "app.h"

#include <cassert>
#include <stdio.h>



static App* GLOBAL_APP = nullptr;

void error_callback(int error, const char* description)
{
    if (GLOBAL_APP == nullptr)
        return;

    GLOBAL_APP->onError(error, description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (GLOBAL_APP == nullptr)
        return;

    GLOBAL_APP->onKey(key, scancode, action, mods);
}

void resize_callback(GLFWwindow* window, int width, int height)
{
    if (GLOBAL_APP == nullptr)
        return;

    GLOBAL_APP->onResize(width, height);
}

struct Vertex {
    float x, y;
    float r, g, b;
};

App::App()
{
}

App::~App()
{
    if (isInitialized_)
        glfwTerminate();
}

void App::init()
{
    if (GLOBAL_APP == nullptr)
        GLOBAL_APP = this;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    isInitialized_ = true;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window_ = glfwCreateWindow(800, 600, "Simple example", NULL, NULL);
    if (!window_) {
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window_, key_callback);
    glfwSetFramebufferSizeCallback(window_, resize_callback);

    glfwMakeContextCurrent(window_);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);
}

void App::run()
{
    assert(isInitialized_);
    assert(window_);

    Vertex vertices[3] = {
        { -0.6f, -0.4f, 1.f, 0.f, 0.f },
        { 0.6f, -0.4f, 0.f, 1.f, 0.f },
        { 0.f, 0.6f, 0.f, 0.f, 1.f }
    };

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    GLint mvp_location = glGetUniformLocation(shaderProgram_, "MVP");
    GLint vpos_location = glGetAttribLocation(shaderProgram_, "vPos");
    GLint vcol_location = glGetAttribLocation(shaderProgram_, "vCol");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
        sizeof(vertices[0]), (void*)0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
        sizeof(vertices[0]), (void*)(sizeof(float) * 2));

    float ratio;
    int width, height;
    mat4x4 m, p, mvp;

    double currentTime = glfwGetTime();
    double lastTime = currentTime;
    double delta = 0;
    while (!glfwWindowShouldClose(window_)) {
        delta = currentTime - lastTime;
        lastTime = currentTime;

        glfwPollEvents();

        glfwGetFramebufferSize(window_, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        mat4x4_identity(m);
        mat4x4_rotate_Z(m, m, (float)glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);

        glUseProgram(shaderProgram_);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window_);

        currentTime = glfwGetTime();
    }

    glfwDestroyWindow(window_);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

void App::setShaders(const char* vertexShader, const char* fragmentShader)
{
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertexShader, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragmentShader, NULL);
    glCompileShader(fragment_shader);

    shaderProgram_ = glCreateProgram();
    glAttachShader(shaderProgram_, vertex_shader);
    glAttachShader(shaderProgram_, fragment_shader);
    glLinkProgram(shaderProgram_);
}

void App::onKey(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window_, GLFW_TRUE);
}

void App::onResize(int width, int height)
{
    fprintf(stderr, "Resize window: %dx%d\n", width, height);
}

void App::onError(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
