#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <string>

#include "core/gl_headers.h"
#include "core/iapp.h"

namespace core {

void resize_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

class Window {
    friend void resize_callback(GLFWwindow* window, int width, int height);
    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
public:
    Window(int width, int height, std::string title);
    ~Window();

    void setApp(IApp* app);

    void setIcon(std::string path);
    void swapBuffer();

    void close();
    bool isClosed() const;
    void update();

    void onResize(int width, int height);

    int width;
    int height;
    float ratio;
    double cursorX;
    double cursorY;

private:
    GLFWwindow* window_ = nullptr;    
    IApp* app_ = nullptr;
};
}
#endif // CORE_WINDOW_H
