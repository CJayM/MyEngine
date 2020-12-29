#include "texture.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "other/stb_image.h"
#endif

namespace core {

Texture::Texture(const std::string& filePath, bool useAlpha)
    : path(filePath)
{
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    {

        // Set our texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Set texture filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Load, create texture and generate mipmaps
        GLFWimage image;
        int numChannels = 3;
        if (useAlpha)
            numChannels = 4;
        image.pixels = stbi_load(filePath.data(), &image.width, &image.height, nullptr, numChannels);
        if (image.pixels) {
            if (useAlpha)
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.pixels);
            else
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.width, image.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.pixels);
            glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(image.pixels);

            size.width = image.width;
            size.height = image.height;
        }
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}
}
