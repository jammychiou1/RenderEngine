#include "ShaderProgram.h"

#include <fstream>
#include <iostream>

ShaderProgram::ShaderProgram(const std::string& shader_path) {

    _program = glCreateProgram();

    std::string vertex_shader_path = shader_path + ".vs";
    std::string fragmet_shader_path = shader_path + ".fs";

    std::string vertex_shader_src = ShaderProgram::_getShaderSrc(vertex_shader_path);
    std::string fragment_shader_src = ShaderProgram::_getShaderSrc(fragmet_shader_path);

    _vertex_shader = ShaderProgram::_create_shader(vertex_shader_src, GL_VERTEX_SHADER);
    _fragment_shader = ShaderProgram::_create_shader(fragment_shader_src, GL_FRAGMENT_SHADER);

    glAttachShader(_program, _vertex_shader);
    glAttachShader(_program, _fragment_shader);

    glLinkProgram(_program);

    ShaderProgram::_checkProgramError(_program, GL_LINK_STATUS, "Error: Failed while linking program ");

    glValidateProgram(_program);

    ShaderProgram::_checkProgramError(_program, GL_VALIDATE_STATUS, "Error: Invalid program ");

    _trans = glGetUniformLocation(_program, "u_trans");
    _cam = glGetUniformLocation(_program, "u_cam");
    _light = glGetUniformLocation(_program, "u_light");
    _cam_pos = glGetUniformLocation(_program, "u_cam_pos");
}

ShaderProgram::~ShaderProgram() {
    glDetachShader(_program, _vertex_shader);
    glDetachShader(_program, _fragment_shader);

    glDeleteShader(_vertex_shader);
    glDeleteShader(_fragment_shader);

    glDeleteProgram(_program);
}

void ShaderProgram::bindProgram() {
    glUseProgram(_program);
}

void ShaderProgram::update(const Transform& trans) {
    glUniformMatrix4fv(_trans, 1, GL_FALSE, &trans.getModel()[0][0]);
}

void ShaderProgram::update(const Camera& cam) {
    glUniformMatrix4fv(_cam, 1, GL_FALSE, &cam.getViewProj()[0][0]);
    glm::vec3 tmp = cam.getPos();
    glUniform3fv(_cam_pos, 1, (GLfloat*)&tmp);
}

void ShaderProgram::updateLight(const glm::vec3& pos) {
    glUniform3fv(_light, 1, (GLfloat*)&pos);
}

void ShaderProgram::_checkShaderError(GLenum flag, const std::string& error_message) {
    GLint success;
    GLchar error[1024] = "";

    glGetShaderiv(shader, flag, &success);
    if (success == GL_FALSE) {
        glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        std::cerr << error_message << ":\n " << error << std::endl;
    }
}

void ShaderProgram::_checkProgramError(GLenum flag, const std::string& error_message) {
    GLint success;
    GLchar error[1024] = "";

    glGetProgramiv(program, flag, &success);
    if (success == GL_FALSE) {
        glGetProgramInfoLog(program, sizeof(error), NULL, error);
        std::cerr << error_message << ":\n " << error << std::endl;
    }
}

std::string ShaderProgram::_getShaderSrc(const std::string& file_name) {

    std::ifstream file;
    file.open(file_name.c_str());

    std::string output;
    std::string line;

    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else {
		std::cerr << "Error: Unable to load shader (" << file_name << ")" << std::endl;
    }

    file.close();
    return output;

}

GLuint ShaderProgram::_createShaders(const std::string& src, GLenum type) {
    GLuint shader = glCreateShader(type);

    const GLchar *ptr = src.c_str();
    GLint len = src.length();

    glShaderSource(shader, 1, &ptr, &len);

    glCompileShader(shader);

    ShaderProgram::_checkShaderError(shader, GL_COMPILE_STATUS, "Error: Failed while compiling shader. ");

    return shader;
}
