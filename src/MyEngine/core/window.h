#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <string>

#include "core/gl_headers.h"
#include "core/iapp.h"

namespace core {

void resize_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class Window {
    friend void resize_callback(GLFWwindow* window, int width, int height);
    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
public:
    Window(int width, int height, std::string title);
    void setApp(IApp* app);
    ~Window();

    void setIcon(std::string path);
    void swapBuffer();

    void close();
    bool isClosed() const;

    void onResize(int width, int height);

    int width;
    int height;
    float ratio;

private:
    GLFWwindow* window_ = nullptr;    
    IApp* app_ = nullptr;
};
}
#endif // CORE_WINDOW_H
