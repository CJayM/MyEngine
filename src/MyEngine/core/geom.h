#ifndef CORE_GEOM_H
#define CORE_GEOM_H

namespace core {

struct Coord2D {
    float x, y;

    Coord2D();
    Coord2D(float x, float y);
    Coord2D(const Coord2D& other);

    Coord2D operator+(const Coord2D& other);
    Coord2D operator-(const Coord2D& other);
};

struct Coord3D{
    float x, y, z;
};

struct Color3f {
    float r, g, b;
};

struct UV{
    float u, v;
};

struct Vertex3D {
    Coord3D pos;
    Color3f color;
    UV uv;
};

}

#endif // CORE_GEOM_H
