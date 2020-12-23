#include "key_constants.h"
#include "scene.h"

#include <math.h>

#include "core/shader.h"
#include "core/texture.h"

namespace core {

Scene::Scene()
{
    material = std::make_shared<Material>(
        std::make_shared<Shader>("resources\\shaders\\default.vert",
            "resources\\shaders\\default.frag"),
        std::make_shared<Texture>("resources\\images\\720_icylake.jpg"));

    mesh = std::make_shared<Mesh>();
}

Scene::~Scene()
{
}

void Scene::update(float current, float delta, float ratio)
{
    camera_.setRatio(ratio);

    float pulseColor = sin(current) / 2.0f + 0.5f;
    material->use(&camera_);
    material->shader->setBaseColor({ 1 - pulseColor, pulseColor, pulseColor });
    mesh->draw();
}

void Scene::onKey(int key, int scancode, int action, int mods)
{
    fprintf(stdout, "Key: %d\n", key);
    fflush(stdout);

    if (key == KeyConstats::ARROW_LEFT)
        camera_.left(0.025);
    if (key == KeyConstats::ARROW_UP)
        camera_.up(0.025);
    if (key == KeyConstats::ARROW_RIGHT)
        camera_.right(0.025);
    if (key == KeyConstats::ARROW_DOWN)
        camera_.down(0.025);

    if (key == KeyConstats::NUM_MINUS)
        camera_.zoomIn(0.025);
    if (key == KeyConstats::NUM_PLUS)
        camera_.zoomOut(0.025);
}
}
