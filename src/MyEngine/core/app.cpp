#include "app.h"

#include <cassert>
#include <iostream>
#include <stdio.h>

#include "other/stb_image.h"

namespace core {

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
    fflush(stderr);
}

App::App()
    : IApp()
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
}

void App::run()
{
    assert(isInitialized_);

    double currentTime = glfwGetTime();
    double lastTime = currentTime;
    double delta = 0;

    while (!needExit_) {
        if (currentWindow_->isClosed())
            break;

        delta = currentTime - lastTime;
        lastTime = currentTime;
        // update
        glfwPollEvents();
        currentWindow_->update();

        if (scene_) {
            scene_->onMouseMove(currentWindow_->cursorPos);
            scene_->update(currentTime, delta);
        }

        // draw
        glViewport(0, 0, currentWindow_->size.width, currentWindow_->size.height);

        if (scene_) {
            scene_->draw();
        }

        currentWindow_->swapBuffer();
        currentTime = glfwGetTime();
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

std::shared_ptr<Window> App::createWindow(const Size& pSize, std::string title)
{
    auto result = std::make_shared<Window>(pSize, title);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    glewInit();

    if (currentWindow_ == nullptr)
        currentWindow_ = result;

    result->setApp(this);
    return result;
}

void App::setScene(Scene* scene)
{
    scene_ = scene;
}

void App::onKey(Window* wnd, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        wnd->close();
        needExit_ = true;
    }

    if (scene_ != nullptr)
        scene_->onKey(key, scancode, action, mods);
}

void App::onResize(Window* wnd, const Size& size)
{
    scene_->updateSize(size);
}

void App::onMouseMove(Window* wnd, const Coord2D& coord)
{
    //    if (scene_ != nullptr)
    //        scene_->onMouseMove(xPos, yPos);
}

void App::onMouseClick(Window* wnd, int key, int action, int mods)
{
    if (scene_ != nullptr)
        scene_->onMouseClick(key, action, mods);
}

void App::onMouseScroll(Window *wnd, float scrollX, float scrollY)
{
    if (scene_ != nullptr)
        scene_->onMouseScroll(scrollX, scrollY);
}
}
