#include "sprite_sheet.h"

namespace core {
namespace sprites {
    Sequence::Sequence()
    {
    }

    SpriteSheet::SpriteSheet()
        : Mesh()
    {
    }

    SpriteSheet::~SpriteSheet()
    {
    }

    void SpriteSheet::addAnimation(std::string name, SpriteAnimation &animation)
    {
        animations_[name] = animation;
    }

    std::pair<std::vector<Vertex3D>, std::vector<GLuint> > SpriteSheet::makeGeometry()
    {
        std::vector<Vertex3D> points = {
            { { 100.0, 100.0, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
            { { 100, -100.0, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
            { { -100, -100, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
            { { -100, 100, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } }
        };
        std::vector<GLuint> indices = {
            0, 1, 3, // First Triangle
            1, 2, 3 // Second Triangle
        };

        return { points, indices };
    }

    SpriteAnimation::SpriteAnimation()
    {
        Sequence salute;
        salute.texture_ = new core::Texture("resources\\spritesheets\\units\\cosmo_artillery_br.png");
        salute.name = "salute";
        salute.frames = {
            { 76, 68, 298, 326, 100, 73, 260, 260 },
            { 76, 68, 152, 409, 100, 73, 260, 260 },
            { 75, 68, 78, 488, 99, 72, 260, 260 },
            { 74, 66, 444, 396, 100, 72, 260, 260 },
            { 73, 66, 0, 628, 99, 71, 260, 260 },
            { 74, 66, 514, 306, 97, 69, 260, 260 },
            { 74, 64, 652, 0, 96, 68, 260, 260 },
            { 73, 60, 718, 0, 98, 68, 260, 260 },
            { 73, 60, 646, 323, 96, 68, 260, 260 },
            { 74, 58, 444, 628, 96, 67, 260, 260 },
            { 74, 58, 708, 323, 95, 67, 260, 260 },
            { 74, 58, 774, 83, 95, 67, 260, 260 },
            { 74, 58, 780, 0, 95, 67, 260, 260 },
            { 75, 58, 152, 733, 95, 66, 260, 260 },
            { 75, 58, 716, 241, 94, 66, 260, 260 },
            { 75, 58, 286, 707, 94, 66, 260, 260 },
            { 75, 58, 588, 486, 94, 66, 260, 260 },
            { 75, 58, 374, 639, 94, 66, 260, 260 },
            { 75, 58, 514, 536, 95, 66, 260, 260 },
            { 74, 58, 780, 163, 95, 67, 260, 260 },
            { 74, 58, 0, 787, 95, 67, 260, 260 },
            { 73, 58, 776, 241, 96, 68, 260, 260 },
            { 72, 60, 650, 410, 96, 69, 260, 260 },
            { 71, 60, 78, 797, 97, 70, 260, 260 },
            { 72, 62, 710, 83, 97, 70, 260, 260 },
            { 72, 64, 650, 241, 97, 71, 260, 260 },
            { 73, 64, 226, 632, 99, 72, 260, 260 },
            { 73, 66, 294, 556, 98, 72, 260, 260 },
            { 74, 66, 226, 556, 100, 73, 260, 260 },
            { 75, 66, 584, 0, 101, 73, 260, 260 },
            { 76, 68, 440, 83, 100, 73, 260, 260 }
        };
    }
}
}
