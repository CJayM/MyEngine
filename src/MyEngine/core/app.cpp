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

App::App(std::string title)
    : title_(title)
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

    window_ = glfwCreateWindow(800, 600, title_.c_str(), NULL, NULL);
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


    double currentTime = glfwGetTime();
    double lastTime = currentTime;
    double delta = 0;
    while (!glfwWindowShouldClose(window_)) {
        delta = currentTime - lastTime;
        lastTime = currentTime;

        glfwPollEvents();

        glfwGetFramebufferSize(window_, &width_, &height_);
        ratio = width_ / (float)height_;

        glViewport(0, 0, width_, height_);
        glClear(GL_COLOR_BUFFER_BIT);

        camera_.setAngle(glfwGetTime());
        camera_.setRatio(ratio);

        glUseProgram(shader->program);
        shader->setMatrix(camera_.getMatrix());
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
