#include "Texture.h"

#include "stb_image.h"

#include <iostream>

Texture::Texture(const std::string& file_name) {
    int width, height;
    stbi_uc* image = stbi_load(file_name.c_str(), &width, &height, nullptr, 4);
    if (!image) {
        std::cerr << file_name << " loading failed." << std::endl;
    }
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 5);

    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    stbi_image_free(image);
}

Texture::~Texture() {
    glDeleteTextures(1, &_texture);
}

void Texture::bindTexture() {
    glBindTexture(GL_TEXTURE_2D, _texture);
}
