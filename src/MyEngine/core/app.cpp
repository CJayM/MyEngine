#include "app.h"

#include <cassert>
#include <iostream>
#include <math.h>
#include <stdio.h>

#include "other/stb_image.h"

namespace core {

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
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

    window = new Window(800, 600, "My game");
    window->setIcon("resources/app_icon.png");

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    glewInit();
}

void App::run()
{
    assert(isInitialized_);

    auto mesh = new Mesh();
    auto shader = new Shader("resources\\shaders\\default.vert",
        "resources\\shaders\\default.frag");
    auto texture = new Texture("resources\\images\\720_icylake.jpg");

    double currentTime = glfwGetTime();
    double lastTime = currentTime;
    double delta = 0;

    while (window->isClosed() == false) {
        delta = currentTime - lastTime;
        lastTime = currentTime;

        glfwPollEvents();

        glViewport(0, 0, window->width, window->height);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        camera_.setAngle(currentTime * 0.4);
        camera_.setRatio(window->ratio);

        float pulseColor = sin(currentTime) / 2.0f + 0.5f;
        shader->use();
        shader->setBaseColor({ 1 - pulseColor, pulseColor, pulseColor });
        shader->setTexture(texture->id);
        shader->setMatrix(camera_.getMatrix());
        mesh->draw();

        window->swapBuffer();
        currentTime = glfwGetTime();
    }

    delete window;
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
}
