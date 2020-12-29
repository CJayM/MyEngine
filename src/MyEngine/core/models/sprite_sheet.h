#ifndef CORE_SPRITESHEET_H
#define CORE_SPRITESHEET_H

#include <map>
#include <string>
#include <vector>

#include <core/mesh.h>
#include <core/texture.h>

namespace core {
namespace sprites {

    struct Frame {
        int w;
        int h;
        int x;
        int y;
        int offsetX;
        int offsetY;
        int sizeX;
        int sizeY;
    };

    struct Sequence {
        std::string name;
        std::vector<Frame> frames;
        core::Texture* texture_ = nullptr;

        Sequence();
    };

    class SpriteAnimation {
    public:
        SpriteAnimation();
    };

    class SpriteSheet : public core::Mesh {
    public:
        SpriteSheet();
        virtual ~SpriteSheet();

        void addAnimation(std::string name, SpriteAnimation& animation);

        // Mesh interface
    protected:
        std::pair<std::vector<Vertex3D>, std::vector<GLuint>> makeGeometry() override;

    private:
        std::map<std::string, SpriteAnimation> animations_;
    };
}
}

#endif // CORE_SPRITESHEET_H
