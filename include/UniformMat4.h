#ifndef UNIFORMMAT4_H
#define UNIFORMMAT4_H

#include "glm/glm.hpp"

#include <Uniform.h>

class UniformMat4 : public Uniform
{
    public:
        UniformMat4(const std::string& name);
        virtual ~UniformMat4();

        void setMat(glm::mat4 mat) {_mat = mat;}
        void load() override;

    private:
        glm::mat4 _mat;
};

#endif // UNIFORMMAT4_H
