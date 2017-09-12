#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

Camera::Camera(glm::vec3 pos, glm::vec3 forward, glm::vec3 up, float fov, float z_near, float z_far, float aspect_r)
        : _pos(pos), _forward(forward), _up(up), _proj(glm::perspective(fov, aspect_r, z_near, z_far)) {}

Camera::~Camera() {}

glm::mat4 Camera::getViewProj() const {
    return _proj * glm::lookAt(_pos, _pos + _forward, _up);
}
