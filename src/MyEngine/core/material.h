#ifndef CORE_MATERIAL_H
#define CORE_MATERIAL_H

#include <memory>

#include "core/shader.h"
#include "core/texture.h"
#include "core/camera.h"

namespace core {

class Material {
public:
    Material(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);

    void use(Camera* camera);

    std::shared_ptr<Shader> shader = nullptr;
    std::shared_ptr<Texture> texture = nullptr;
};
}

#endif // CORE_MATERIAL_H
