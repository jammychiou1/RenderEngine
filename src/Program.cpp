#include "Program.h"

#include <iostream>

#include "Shader.h"

Program::Program() {
    _handle = glCreateProgram();
}

Program::~Program() {
    glDeleteProgram(_handle);
}

void Program::addUniform(Uniform* uniform) {
    _uniforms.push_back(uniform);
}

void Program::build(const std::string& vertex_shader_src, const std::string& fragment_shader_src) {
    Shader vertex_shader(vertex_shader_src, GL_VERTEX_SHADER);
    Shader fragment_shader(fragment_shader_src, GL_FRAGMENT_SHADER);

    glAttachShader(_handle, vertex_shader.getHandle());
    glAttachShader(_handle, fragment_shader.getHandle());

    glBindAttribLocation(_handle, 0, "v_position");
    glBindAttribLocation(_handle, 1, "v_tex_coord");
    glBindAttribLocation(_handle, 2, "v_normal");

    glLinkProgram(_handle);
    _checkError(GL_LINK_STATUS, "Error: Failed while linking program");

    glValidateProgram(_handle);
    _checkError(GL_LINK_STATUS, "Error: Invalid program");

    glDetachShader(_handle, vertex_shader.getHandle());
    glDetachShader(_handle, fragment_shader.getHandle());

    for (Uniform* uniform : _uniforms) {
        uniform->setHandle(glGetUniformLocation(_handle, (GLchar*)uniform->getName().c_str()));
    }
}

void Program::use() {
    glUseProgram(_handle);
}

void Program::update() {
    for (Uniform* uniform : _uniforms) {
        uniform->load();
    }
}

void Program::_checkError(GLenum flag, const std::string& error_message) {
    GLint success;
    GLchar error[1024] = "";

    glGetProgramiv(_handle, flag, &success);
    if (success == GL_FALSE) {
        glGetProgramInfoLog(_handle, sizeof(error), NULL, error);
        std::cerr << error_message << "\n" << error << std::endl;
    }
}
