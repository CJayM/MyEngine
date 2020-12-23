#ifndef CORE_SCENE_H
#define CORE_SCENE_H

#include "core/camera.h"
#include "core/material.h"
#include "core/mesh.h"

namespace core {

class Scene
{
public:
    Scene();
    virtual ~Scene();
    void update(float current, float delta, float ratio);

    virtual void onKey(int key, int scancode, int action, int mods);

protected:
    Camera camera_;
    std::shared_ptr<Material> material = nullptr;
    std::shared_ptr<Mesh> mesh;


};

}

#endif // CORE_SCENE_H
