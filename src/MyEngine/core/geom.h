#ifndef CORE_GEOM_H
#define CORE_GEOM_H

namespace core {

struct Coord2D {
    float x, y;
};

struct Color3f {
    float r, g, b;
};

struct Vertex {
    Coord2D pos;
    Color3f color;
};
}

#endif // CORE_GEOM_H
