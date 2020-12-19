#ifndef CORE_APP_H
#define CORE_APP_H

#include "model.h"
#include "simple_shader.h"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/linmath.h>

namespace core {

class App {
public:
    App();
    ~App();
    void init();
    void run();

    void onKey(int key, int scancode, int action, int mods);
    void onResize(int width, int height);
    void onError(int error, const char* description);

protected:
private:
    bool isInitialized_ = false;
    GLFWwindow* window_ = nullptr;

    Model* triangle = nullptr;
    SimpleShader* shader = nullptr;
};
}
#endif // CORE_APP_H
