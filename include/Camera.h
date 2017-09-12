#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
    public:
        Camera(glm::vec3 pos, glm::vec3 forward, glm::vec3 up, float fov, float z_near, float z_far, float aspect_r);
        virtual ~Camera();

        glm::vec3 getPos() const {return _pos;}
        glm::vec3 getForward() const {return _forward;}
        glm::vec3 getUp() const {return _up;}
        glm::vec3 getRight() const {return glm::cross(_forward, _up);}

        void setPos(glm::vec3 pos) {_pos = pos;}
        void setRot(glm::vec3 forward, glm::vec3 up) {_forward = forward; _up = up;}

        glm::mat4 getViewProj() const;

    private:
        glm::vec3 _pos;
        glm::vec3 _forward;
        glm::vec3 _up;
        glm::mat4 _proj;
};

#endif // CAMERA_H
