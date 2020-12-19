#ifndef GEOM_H
#define GEOM_H


struct Coord2D{
    float x, y;
};

struct Color3f{
    float r,g,b;
};

struct Vertex{
    Coord2D pos;
    Color3f color;
};

#endif // GEOM_H
