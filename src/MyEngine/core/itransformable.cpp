#include "itransformable.h"

void core::ITransformable::setPosition(const core::Coord2D &pos)
{
    pos_.x = pos.x;
    pos_.y = pos.y;
}

core::Coord2D &core::ITransformable::getPosition()
{
    return pos_;
}
