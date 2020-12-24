#ifndef CORE_SCENE_H
#define CORE_SCENE_H

#include "core/camera.h"
#include "core/material.h"
#include "core/mesh.h"

namespace core {

class Scene
{
public:
    Scene(float width, float height);
    virtual ~Scene();
    void update(float current, float delta);
    void updateSize(float width, float height);

    virtual void onKey(int key, int scancode, int action, int mods);

protected:
    std::shared_ptr<Camera> camera_ = nullptr;
    std::shared_ptr<Material> material = nullptr;
    std::shared_ptr<Mesh> mesh;

    const float width_;
    const float height_;
    const float ratio_;
};

}

#endif // CORE_SCENE_H
