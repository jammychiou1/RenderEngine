#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include <string>

class Texture
{
    public:
        Texture(const std::string& file_name);
        virtual ~Texture();
        void bindTexture();

    private:
        GLuint _texture;
};

#endif // TEXTURE_H
