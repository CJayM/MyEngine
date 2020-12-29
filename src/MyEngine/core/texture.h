#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include "core/gl_headers.h"
#include "core/geom.h"

#include <string>


namespace core {

class Texture {
public:
    Texture(const std::string& filePath, bool useAlpha = true);
    GLuint id;

    const std::string path;
    core::Size size;

};

}

#endif // CORE_TEXTURE_H
