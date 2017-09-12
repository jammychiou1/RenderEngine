#include "Shader.h"

#include <iostream>

Shader::Shader(const std::string& src, GLenum type) {
    _handle = glCreateShader(type);

    const GLchar *ptr = src.c_str();
    GLint len = src.length();

    glShaderSource(_handle, 1, &ptr, &len);

    glCompileShader(_handle);

    _checkError();
}

Shader::~Shader() {
    glDeleteShader(_handle);
}

void Shader::_checkError() {
    GLint success;
    GLchar error[1024] = "";

    glGetShaderiv(_handle, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        glGetShaderInfoLog(_handle, sizeof(error), NULL, error);
        std::cerr << "Error: Failed while compiling shader\n" << error << std::endl;
    }
}
