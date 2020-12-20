#include "app.h"

#include <cassert>
#include <stdio.h>

namespace core {

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
    fflush(stderr);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void resize_callback(GLFWwindow* window, int width, int height)
{
    fprintf(stderr, "Resize window: %dx%d\n", width, height);
    fflush(stderr);
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
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    isInitialized_ = true;

    window_ = glfwCreateWindow(800, 600, title_.c_str(), nullptr, nullptr);
    if (!window_) {
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window_, key_callback);
    glfwSetFramebufferSizeCallback(window_, resize_callback);

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    glewInit();
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

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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
}
