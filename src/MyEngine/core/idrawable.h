#ifndef CORE_IDRAWABLE_H
#define CORE_IDRAWABLE_H

#include "core/camera.h"

namespace core {


class IDrawable
{
public:
    IDrawable() = default;
    virtual ~IDrawable();

    virtual void draw(const Camera& camera) = 0;
};

}

#endif // CORE_IDRAWABLE_H
