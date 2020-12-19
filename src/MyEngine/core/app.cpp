#include "app.h"

#include <cassert>
#include <stdio.h>

namespace core {

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

    triangle = new Model();
    shader = new SimpleShader();

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

        glUseProgram(shader->program);
        shader->setMatrix(mvp);
        triangle->draw();

        glfwSwapBuffers(window_);

        currentTime = glfwGetTime();
    }

    glfwDestroyWindow(window_);

    glfwTerminate();
    exit(EXIT_SUCCESS);
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
}
