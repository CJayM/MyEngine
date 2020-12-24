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

core::Coord2D core::Coord2D::operator+(const core::Coord2D &other)
{
    return core::Coord2D(x + other.x, y + other.y);
}

core::Coord2D core::Coord2D::operator-(const core::Coord2D &other)
{
    return core::Coord2D(x - other.x, y - other.y);
}
