#include "geom.h"

core::Coord2D::Coord2D()
    : x(0)
    , y(0)
{
}

core::Coord2D::Coord2D(float pX, float pY)
    : x(pX)
    , y(pY)
{
}

core::Coord2D::Coord2D(const core::Coord2D& other)
    : x(other.x)
    , y(other.y)
{
}

core::Coord2D core::Coord2D::operator+(const core::Coord2D &other) const
{
    return core::Coord2D(x + other.x, y + other.y);
}

core::Coord2D core::Coord2D::operator-(const core::Coord2D &other) const
{
    return core::Coord2D(x - other.x, y - other.y);
}

core::Coord2D core::Coord2D::operator*(float value) const
{
    return core::Coord2D(x * value, y * value);
}

core::Coord2D core::Coord2D::operator*(const Coord2D& value) const
{
    return core::Coord2D(x * value.x, y * value.y);
}
