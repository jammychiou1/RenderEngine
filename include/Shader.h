#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <string>

class Shader
{
    public:
        Shader(const std::string& src, GLenum type);
        virtual ~Shader();

        GLuint getHandle() {return _handle;}

    private:
        GLuint _handle;

        void _checkError();
};

#endif // SHADER_H
