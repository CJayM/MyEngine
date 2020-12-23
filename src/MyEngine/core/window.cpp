#include "window.h"

#include "other/stb_image.h"

void resize_callback(GLFWwindow* window, int width, int height)
{
    auto wnd = reinterpret_cast<core::Window*>(glfwGetWindowUserPointer(window));
    if (wnd)
        wnd->onResize(width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    auto wnd = reinterpret_cast<core::Window*>(glfwGetWindowUserPointer(window));
    if (wnd)
        wnd->onKey(key, scancode, action, mods);
}

namespace core {

Window::Window(int width, int height, std::string pTitle)
{
    window_ = glfwCreateWindow(width, height, pTitle.c_str(), nullptr, nullptr);
    if (window_ == nullptr) {
        exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(window_, this);

    glfwSetKeyCallback(window_, key_callback);
    glfwSetFramebufferSizeCallback(window_, resize_callback);

    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    int w, h;
    glfwGetFramebufferSize(window_, &w, &h);
    onResize(w, h);
}

Window::~Window()
{
    glfwDestroyWindow(window_);
}

void Window::setIcon(std::string path)
{
    GLFWimage icons[1];
    icons[0].pixels = stbi_load(path.c_str(), &icons[0].width, &icons[0].height, nullptr, 4);
    glfwSetWindowIcon(window_, 1, icons);
    stbi_image_free(icons[0].pixels);
}

void Window::swapBuffer()
{
    glfwSwapBuffers(window_);
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(window_);
}

void Window::onKey(int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window_, GL_TRUE);
}

void Window::onResize(int pWidth, int pHeight)
{
    width = pWidth;
    height = pHeight;

    ratio = width / float(height);
}
}
