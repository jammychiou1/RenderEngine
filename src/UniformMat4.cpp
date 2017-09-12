#include "UniformMat4.h"

UniformMat4::UniformMat4(const std::string& name) : Uniform(name) {}

UniformMat4::~UniformMat4() {}

void UniformMat4::load() {
    glUniformMatrix4fv(_handle, 1, GL_FALSE, (GLfloat*)(&_mat[0][0]));
}
