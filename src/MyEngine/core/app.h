#ifndef CORE_APP_H
#define CORE_APP_H

#include "camera.h"
#include "model.h"
#include "shader.h"

#include "core/gl_headers.h"

namespace core {

class App {
public:
    App(std::string title="Core app");
    virtual ~App();
    void init();
    void run();



protected:
    std::string title_;
    bool isInitialized_ = false;
    GLFWwindow* window_ = nullptr;
    int width_;
    int height_;
    Camera camera_;

    Model* triangle = nullptr;
    Shader* shader = nullptr;
};
}
#endif // CORE_APP_H
