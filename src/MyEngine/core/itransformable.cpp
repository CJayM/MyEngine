#include "itransformable.h"

core::ITransformable::~ITransformable()
{
}

void core::ITransformable::setPosition(const core::Coord2D &pos)
{
    pos_.x = pos.x;
    pos_.y = pos.y;
}

const core::Coord2D &core::ITransformable::getPosition() const
{
    return pos_;
}

core::Coord2D &core::ITransformable::getPosition()
{
    return pos_;
}
