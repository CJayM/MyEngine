#ifndef CORE_IAPP_H
#define CORE_IAPP_H

namespace core {

class Window;

class IApp
{
public:
    IApp();
    virtual ~IApp();

    virtual void onResize(Window* wnd, int width, int height);
    virtual void onKey(Window* wnd, int key, int scancode, int action, int mods) = 0;
};

}

#endif // CORE_IAPP_H
