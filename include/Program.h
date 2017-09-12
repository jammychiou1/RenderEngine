#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/glew.h>

#include <vector>

#include "Uniform.h"

class Program
{
    public:
        Program();
        virtual ~Program();

        void addUniform(Uniform* uniform);
        void build(const std::string& vertex_shader_src, const std::string& fragment_shader_src);
        void use();
        void update();

    private:
        GLuint _handle;

        std::vector<Uniform*> _uniforms;

        void _checkError(GLenum flag, const std::string& error_message);
};

#endif // PROGRAM_H
