#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include "core/gl_headers.h"
#include "core/geom.h"

#include <string>


namespace core {

class Texture {
public:
    Texture();
    GLuint id;
    bool loadFromFile(const std::string& filePath, bool useAlpha = true);

    core::Size size;

private:
    std::string path_;
    bool useAlpha_ = false;

};

}

#endif // CORE_TEXTURE_H
