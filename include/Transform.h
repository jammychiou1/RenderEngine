#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
    public:
        Transform(glm::vec3 pos = glm::vec3(), glm::vec3 rot = glm::vec3(), glm::vec3 scl = glm::vec3(1));
        virtual ~Transform();

        glm::mat4 getModel() const;

        glm::vec3& getPos();
        glm::vec3& getRot();
        glm::vec3& getScl();

    private:
        glm::vec3 _pos;
        glm::vec3 _rot;
        glm::vec3 _scl;
};

#endif // TRANSFORM_H
