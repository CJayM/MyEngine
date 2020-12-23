#include "material.h"

namespace core {

Material::Material(std::shared_ptr<Shader> pShader, std::shared_ptr<Texture> pTexture)
    : shader(pShader)
    , texture(pTexture)
{
}

void Material::use(Camera* camera)
{
    shader->use();
    shader->setTexture(texture->id);
    shader->setMatrix(camera->getMatrix());
}
}
