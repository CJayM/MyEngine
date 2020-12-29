#ifndef CORE_SPRITES_SPRITE_H
#define CORE_SPRITES_SPRITE_H

#include <memory>

#include "core/mesh.h"
#include "core/texture.h"

namespace core {
namespace sprites {
    class Sprite {
    public:
        Sprite(std::shared_ptr<Texture> texture);
        virtual ~Sprite();

        void init();
        void draw(const Camera& camera);

        Size size;
        std::shared_ptr<Texture> texture_;

        // Mesh interface
    protected:
        virtual std::pair<std::vector<Vertex3D>, std::vector<GLuint>> makeGeometry();

        GLuint id;
        GLuint vbo_;
        GLuint ibo_;
    };

    std::shared_ptr<Sprite> makeSprite(std::shared_ptr<Texture> texture);
}
}

#endif  // CORE_SPRITES_SPRITE_H
