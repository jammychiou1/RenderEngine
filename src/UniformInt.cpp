#include "UniformInt.h"

UniformInt::UniformInt(const std::string& name) : Uniform(name) {}

UniformInt::~UniformInt() {}

void UniformInt::load() {
    glUniform1i(_handle, _integer);
}
