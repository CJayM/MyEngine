#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <string>

#include "core/gl_headers.h"

namespace core {


class Window
{
public:
    Window(int width, int height, std::string title);
    ~Window();

    void setIcon(std::string path);
    void onResize(int width, int height);
    void swap();
    void activate();
    bool isClosed() const;

    float ratio;
    int width;
    int height;
    std::string title;

private:
    GLFWwindow* window = nullptr;
};

}

#endif // CORE_WINDOW_H
