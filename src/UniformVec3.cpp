#include "UniformVec3.h"

UniformVec3::UniformVec3(const std::string& name) : Uniform(name) {};

UniformVec3::~UniformVec3() {}

void UniformVec3::load() {
    glUniform3fv(_handle, 1, (GLfloat*)(&_vec[0]));
}
