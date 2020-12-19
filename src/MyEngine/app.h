#ifndef APP_H
#define APP_H

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/linmath.h>

class App
{
public:
    App();
    ~App();
    void init();
    void run();
    void setShaders(const char* vertexShader, const char* fragmentShader);

    void onKey(int key, int scancode, int action, int mods);
    void onResize(int width, int height);
    void onError(int error, const char* description);

protected:
private:
    bool isInitialized_ = false;
    GLFWwindow* window_ = nullptr;

    GLuint shaderProgram_;
};

#endif // APP_H
