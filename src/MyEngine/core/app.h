#ifndef CORE_APP_H
#define CORE_APP_H

#include "core/gl_headers.h"

#include "core/window.h"
#include "core/camera.h"

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
