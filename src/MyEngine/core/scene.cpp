#include "scene.h"
#include "key_constants.h"

#include <math.h>

#include "core/models/plane.h"
#include "core/shader.h"
#include "core/texture.h"

namespace core {

Scene::Scene(float pWidth, float pHeight)
    : width_(pWidth)
    , height_(pHeight)
{
    material = std::make_shared<Material>(
        std::make_shared<Shader>("resources\\shaders\\default.vert",
            "resources\\shaders\\default.frag"),
        std::make_shared<Texture>("resources\\images\\720_icylake.jpg"));

    mesh = std::make_shared<models::Plane>(width_, height_);
    mesh->initGeometry();
    camera_.reset(new Camera(pWidth, pHeight));
    updateSize(width_, height_);
}

Scene::~Scene()
{
}

void Scene::update(float current, float delta)
{
    camera_->update(mouseX_, mouseY_);

    float pulseColor = sin(current) / 2.0f + 0.5f;
    material->use(camera_.get());
    material->shader->setBaseColor({ 1 - pulseColor, pulseColor, pulseColor });
}

void Scene::updateSize(float pWidth, float pHeight)
{
    camera_->seWindowSize(pWidth, pHeight);
}

void Scene::draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    mesh->draw();
}

void Scene::onKey(int key, int scancode, int action, int mods)
{
    fprintf(stdout, "Key: %d \t %d \t%d\n", key, action, mods);
    fflush(stdout);

    if (action != KeyConstats::PRESS_UP) {
        if (key == KeyConstats::ARROW_LEFT)
            camera_->left(1);
        if (key == KeyConstats::ARROW_UP)
            camera_->up(1);
        if (key == KeyConstats::ARROW_RIGHT)
            camera_->right(1);
        if (key == KeyConstats::ARROW_DOWN)
            camera_->down(1);

        if (key == KeyConstats::NUM_MINUS)
            camera_->scaleUp(0.05);
        if (key == KeyConstats::NUM_PLUS)
            camera_->scaleDown(0.05);
    }
}

void Scene::onMouseMove(double xPos, double yPos)
{
    mouseX_ = xPos;
    mouseY_ = yPos;
}

void Scene::onMouseClick(int key, int action, int mods)
{
    fprintf(stdout, "Mouse: %d \t %d \t%d\n", key, action, mods);
    fflush(stdout);
    if (key == 0) {
        if (action == 1) {
            camera_->startDrag(mouseX_, mouseY_);
        } else {
            camera_->endDrag(mouseX_, mouseY_);
        }
    }
}
}
