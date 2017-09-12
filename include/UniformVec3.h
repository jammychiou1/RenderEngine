#ifndef UNIFORMVEC3_H
#define UNIFORMVEC3_H

#include "Uniform.h"

#include <glm/glm.hpp>

class UniformVec3 : public Uniform
{
    public:
        UniformVec3(const std::string& name);
        virtual ~UniformVec3();

        void setVec(glm::vec3 vec) {_vec = vec;}
        void load() override;

    private:
        glm::vec3 _vec;
};

#endif // UNIFORMVEC3_H
