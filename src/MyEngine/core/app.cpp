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

    GLFWimage icons[1];
    icons[0].pixels = stbi_load("resources/app_icon.png", &icons[0].width, &icons[0].height, nullptr, 4);
    glfwSetWindowIcon(window_, 1, icons);
    stbi_image_free(icons[0].pixels);

    glfwSetKeyCallback(window_, key_callback);
    glfwSetFramebufferSizeCallback(window_, resize_callback);

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    glewInit();

    mesh_ = new Mesh();
    shader = new Shader("resources\\shaders\\default.vert",
        "resources\\shaders\\default.frag");
    texture = new Texture("resources\\images\\720_icylake.jpg");
}

void App::run()
{
    assert(isInitialized_);
    assert(window_);

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

        camera_.setAngle(currentTime*0.4);
        camera_.setRatio(ratio);

        float pulseColor = sin(currentTime) / 2.0f + 0.5f;
        shader->use();
        shader->setBaseColor({ 1 - pulseColor, pulseColor, pulseColor });
        shader->setTexture(texture->id);
        shader->setMatrix(camera_.getMatrix());
        mesh_->draw();

        glfwSwapBuffers(window_);
        currentTime = glfwGetTime();
    }

    glfwDestroyWindow(window_);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}
}
