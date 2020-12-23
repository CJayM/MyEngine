#ifndef CORE_APP_H
#define CORE_APP_H

#include "camera.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "window.h"

#include "core/gl_headers.h"
#include "core/window.h"

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

    Camera camera_;
    Window* window = nullptr;
};
}
#endif // CORE_APP_H
