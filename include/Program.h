#ifndef PROGRAM_H
#define PROGRAM_H

#include <GL/glew.h>

#include <vector>

#include "Uniform.h"
#include "Scene.h"

class Program
{
    public:
        Program();
        virtual ~Program();

//        void addUniform(Uniform* uniform);
        void build(const std::string& vertex_shader_src, const std::string& fragment_shader_src);
//        void use();
        void render(JMChuRE::Scene& scene, JMChuRE::RenderObject& render_object);
//        void update();

        void set_scene(JMChuRE::Scene& scene);
        void set_object(JMChuRE::RenderObject& render_object);

    private:
        GLuint _handle;

//        std::vector<Uniform*> _uniforms;
        GLint _u_use_lighting;
        GLint _u_use_texture;
        GLint _u_default_color;
        GLint _u_cam_pos;
        GLint _u_light_pos;
        GLint _u_camera;
        GLint _u_tranform;

        void _checkError(GLenum flag, const std::string& error_message);
};

#endif // PROGRAM_H
