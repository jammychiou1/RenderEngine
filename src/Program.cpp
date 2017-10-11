#include "Program.h"

#include <iostream>

#include "Shader.h"

Program::Program() {
    _handle = glCreateProgram();
}

Program::~Program() {
    glDeleteProgram(_handle);
}

//void Program::addUniform(Uniform* uniform) {
//    _uniforms.push_back(uniform);
//}

void Program::build(const std::string& vertex_shader_src, const std::string& fragment_shader_src) {
    Shader vertex_shader(vertex_shader_src, GL_VERTEX_SHADER);
    Shader fragment_shader(fragment_shader_src, GL_FRAGMENT_SHADER);

    glAttachShader(_handle, vertex_shader.getHandle());
    glAttachShader(_handle, fragment_shader.getHandle());

    glLinkProgram(_handle);
    _checkError(GL_LINK_STATUS, "Error: Failed while linking program");

    glDetachShader(_handle, vertex_shader.getHandle());
    glDetachShader(_handle, fragment_shader.getHandle());

    glValidateProgram(_handle);
    _checkError(GL_LINK_STATUS, "Error: Invalid program");

    glBindAttribLocation(_handle, 0, "v_position");
    glBindAttribLocation(_handle, 1, "v_tex_coord");
    glBindAttribLocation(_handle, 2, "v_normal");

    _u_use_lighting = glGetUniformLocation(_handle, "u_use_lighting");
    _u_use_texture = glGetUniformLocation(_handle, "u_use_texture");
    _u_default_color = glGetUniformLocation(_handle, "u_default_color");
    _u_cam_pos = glGetUniformLocation(_handle, "u_cam_pos");
    _u_light_pos = glGetUniformLocation(_handle, "u_light_pos");
    _u_camera = glGetUniformLocation(_handle, "u_camera");
    _u_tranform = glGetUniformLocation(_handle, "u_tranform");

//    for (Uniform* uniform : _uniforms) {
//        uniform->setHandle(glGetUniformLocation(_handle, (GLchar*)uniform->getName().c_str()));
//    }
}

//void Program::use() {
//    glUseProgram(_handle);
//}

void Program::render(Camera& camera, glm::vec3 light_pos, std::vector<JMChuRE::RenderObject*>& render_objects) {
    glUniform3fv(_u_light_pos, 1, &light_pos[0]);
    glUniform3fv(_u_camera, 1, &camera.getViewProj()[0][0]);
    for (JMChuRE::RenderObject* render_object : render_objects) {
        glUniformMatrix4fv(_u_tranform, 1, GL_FALSE, &render_object->transform->getModel()[0][0]);
        glUniform1i(_u_use_lighting, render_object->material->get_use_lighting());
        if (!render_object->material->get_texture()) {
            glUniform1i(_u_use_texture, false);
            glUniform3fv(_u_default_color, 1, &render_object->material->get_default_color()[0]);
        }
        else {
            glUniform1i(_u_use_texture, true);
            render_object->material->get_texture()->bindTexture();
        }

        render_object->mesh->draw();
    }
}

//void Program::update() {
//    for (Uniform* uniform : _uniforms) {
//        uniform->load();
//    }
//}

//void Program::set_scene(JMChuRE::Scene& scene) {
//    glUniform3fv(_u_light_pos, 1, &scene.get_light_pos()[0]);
//    glUniform3fv(_u_camera, 1, &scene.get_camera()->getViewProj()[0][0]);
//}
//
//void Program::set_object(JMChuRE::RenderObject& render_object) {
//    glUniformMatrix4fv(_u_tranform, 1, GL_FALSE, &render_object.transform.getModel()[0][0]);
//    glUniform1i(_u_use_lighting, render_object.material.get_use_lighting());
//    if (!render_object.material.get_texture()) {
//        glUniform1i(_u_use_texture, false);
//        glUniform3fv(_u_default_color, 1, &render_object.material.get_default_color()[0]);
//    }
//    else {
//        glUniform1i(_u_use_texture, true);
//        render_object.material.get_texture()->bindTexture();
//    }
//}

void Program::_checkError(GLenum flag, const std::string& error_message) {
    GLint success;
    GLchar error[1024] = "";

    glGetProgramiv(_handle, flag, &success);
    if (success == GL_FALSE) {
        glGetProgramInfoLog(_handle, sizeof(error), NULL, error);
        std::cerr << error_message << "\n" << error << std::endl;
    }
}
