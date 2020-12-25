#ifndef CORE_GEOM_H
#define CORE_GEOM_H

namespace core {

struct Coord2D {
    float x, y;

    Coord2D();
    Coord2D(float x, float y);
    Coord2D(const Coord2D& other);

    Coord2D operator+(const Coord2D& other) const;
    Coord2D operator-(const Coord2D& other) const;
    Coord2D operator*(float value) const;
    Coord2D operator*(const Coord2D& value) const;
};

struct Size{
    Size();
    Size(float width, float height);
    Size(const Size& other);
    float width;
    float height;


    float getRatio() const;
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
