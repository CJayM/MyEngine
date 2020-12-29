#ifndef CORE_SCENE_H
#define CORE_SCENE_H

#include "core/camera.h"
#include "core/material.h"
#include "core/mesh.h"
#include <core/models/sprite_sheet.h>
#include <core/sprites/sprite.h>

namespace core {

class Scene
{
public:
    Scene(const Size& size);
    virtual ~Scene();
    void update(float current, float delta);
    void updateSize(const Size& size);

    void draw();

    virtual void onKey(int key, int scancode, int action, int mods);
    virtual void onMouseMove(const Coord2D& pos);
    virtual void onMouseClick(int key, int action, int mods);
    virtual void onMouseScroll(float scrollX, float scrollY);

protected:
    std::shared_ptr<Camera> camera_ = nullptr;
    std::shared_ptr<Material> material = nullptr;
    std::shared_ptr<Material> spriteMaterial = nullptr;
    std::shared_ptr<Mesh> mesh;

    core::sprites::SpriteSheet soldier_;
    std::shared_ptr<core::sprites::Sprite> drone_;

    const Size size_;
    Coord2D mousePos_;
};

}

#endif // CORE_SCENE_H
