#ifndef CORE_ITRANSFORMABLE_H
#define CORE_ITRANSFORMABLE_H

#include "core/geom.h"

namespace core {

class ITransformable {
public:
    ITransformable();

    void setPosition(const Coord2D& pos);
    Coord2D& getPosition();

protected:
    Coord2D pos_;
};
}

#endif // CORE_ITRANSFORMABLE_H
