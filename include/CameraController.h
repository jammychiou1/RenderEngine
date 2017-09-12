#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include "glm/glm.hpp"

#include "Camera.h"

class CameraController
{
    public:
        CameraController(Camera* camera, glm::vec3 pos, glm::vec2 lng_lat);
        virtual ~CameraController();

        void setVel(glm::vec3 vel) {_vel = vel;}
        void setAngVel(glm::vec2 ang_vel) {_ang_vel = ang_vel;}

        void update();

    private:
        Camera* _camera;

        glm::vec3 _pos;
        glm::vec3 _vel;
        glm::vec2 _lng_lat;
        glm::vec2 _ang_vel;
};

#endif // CAMERACONTROLLER_H
