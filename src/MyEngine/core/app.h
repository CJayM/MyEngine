#ifndef CORE_APP_H
#define CORE_APP_H

#include "camera.h"
#include "model.h"
#include "simple_shader.h"

#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace core {

class App {
public:
    App(std::string title="Core app");
    virtual ~App();
    void init();
    void run();

    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onResize(int width, int height);
    void onError(int error, const char* description);

protected:
    std::string title_;
    bool isInitialized_ = false;
    GLFWwindow* window_ = nullptr;
    int width_;
    int height_;
    Camera camera_;

    Model* triangle = nullptr;
    SimpleShader* shader = nullptr;
};
}
#endif // CORE_APP_H
