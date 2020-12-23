#ifndef CORE_APP_H
#define CORE_APP_H

#include "core/gl_headers.h"

#include "core/camera.h"
#include "core/iapp.h"
#include "core/window.h"
#include <memory>

namespace core {

class App : public IApp {
public:
    App();
    virtual ~App();
    void init();
    void run();
    std::shared_ptr<Window> createWindow(int width, int height, std::string title);

protected:
    std::string title_;
    bool isInitialized_ = false;
    bool needExit_ = false;

    std::shared_ptr<Window> currentWindow_ = nullptr;
    Camera camera_;

    // IApp interface
public:
    void onKey(Window* wnd, int key, int scancode, int action, int mods);
};
}
#endif // CORE_APP_H
