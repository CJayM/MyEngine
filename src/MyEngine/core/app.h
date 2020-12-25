#ifndef CORE_APP_H
#define CORE_APP_H

#include "core/gl_headers.h"

#include "core/camera.h"
#include "core/iapp.h"
#include "core/window.h"
#include "core/scene.h"

#include <memory>

namespace core {

class App : public IApp {
public:
    App();
    virtual ~App();
    void init();
    void run();
    std::shared_ptr<Window> createWindow(const Size& size, std::string title);
    void setScene(Scene* scene);

protected:
    std::string title_;
    bool isInitialized_ = false;
    bool needExit_ = false;

    std::shared_ptr<Window> currentWindow_ = nullptr;
    Scene* scene_ = nullptr;

    // IApp interface
public:
    void onKey(Window* wnd, int key, int scancode, int action, int mods);
    void onResize(Window *wnd, const Size& size);
    void onMouseMove(Window *wnd, const Coord2D& pos);
    void onMouseClick(Window *wnd, int key, int action, int mods);
    void onMouseScroll(Window *wnd, float scrollX, float scrollY);
};
}
#endif // CORE_APP_H
