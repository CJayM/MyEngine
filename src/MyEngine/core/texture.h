#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include "core/gl_headers.h"

#include <string>


namespace core {

class Texture {
public:
    Texture(const std::string& filePath);
    GLuint id;
};

}

#endif // CORE_TEXTURE_H
