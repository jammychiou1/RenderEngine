#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

#include "Transform.h"
#include "Camera.h"

class ShaderProgram
{
    public:
        ShaderProgram(const std::string& shader_path);
        virtual ~ShaderProgram();
        void bindProgram();
        void update(const Transform& trans);
        void update(const Camera& cam);
        void updateLight(const glm::vec3& pos);

    private:
        GLuint _program;
        GLuint _vertex_shader;
        GLuint _fragment_shader;
        GLint _trans;
        GLint _cam;
        GLint _light;
        GLint _cam_pos;

        void _checkShaderError(GLenum flag, const std::string& error_message);
        void _checkProgramError(GLenum flag, const std::string& error_message);
        GLuint _createShaders(const std::string& src, GLenum type);
        static std::string _getShaderSrc(const std::string& shader_path);
};

#endif // SHADERPROGRAM_H
