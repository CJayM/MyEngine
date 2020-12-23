#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <string>

#include "core/gl_headers.h"

namespace core {

class Window {
public:
    Window(int width, int height, std::string title);
    virtual ~Window();

    void setIcon(std::string path);
    void swapBuffer();

    bool isClosed() const;

    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onResize(int width, int height);

    int width;
    int height;
    float ratio;

private:
    GLFWwindow* window_ = nullptr;
};
}
#endif // CORE_WINDOW_H
