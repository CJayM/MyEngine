#include "window.h"

#include "other/stb_image.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void resize_callback(GLFWwindow* window, int width, int height)
{
    auto wnd = reinterpret_cast<core::Window*>(glfwGetWindowUserPointer(window));
    wnd->onResize(width, height);
}

namespace core {

Window::Window(int width, int height, std::string title)
    : width(width)
    , height(height)
    , title(title)
{
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, resize_callback);

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    onResize(w, h);
}

Window::~Window()
{
    glfwDestroyWindow(window);
}

void Window::setIcon(std::string path)
{
    GLFWimage icons[1];
    icons[0].pixels = stbi_load(path.c_str(), &icons[0].width, &icons[0].height, nullptr, 4);
    glfwSetWindowIcon(window, 1, icons);
    stbi_image_free(icons[0].pixels);
}

void Window::onResize(int pWidth, int pHeight)
{
    fprintf(stdout, "Resize window: %dx%d\n", width, height);
    fflush(stdout);

    width = pWidth;
    height = pHeight;

    ratio = width / (float)height;
}

void Window::swap()
{
    glfwSwapBuffers(window);
}

void Window::activate()
{
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(window);
}
}
