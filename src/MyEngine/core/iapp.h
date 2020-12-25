#ifndef CORE_IAPP_H
#define CORE_IAPP_H

#include "core/geom.h"

namespace core {

class Window;

class IApp
{
public:
    IApp();
    virtual ~IApp();

    virtual void onResize(Window* wnd, const Size& size) = 0;
    virtual void onKey(Window* wnd, int key, int scancode, int action, int mods) = 0;
    virtual void onMouseMove(Window* wnd, const Coord2D& pos) = 0;
    virtual void onMouseClick(Window* wnd, int key, int action, int mods) = 0;
};

}

#endif // CORE_IAPP_H
