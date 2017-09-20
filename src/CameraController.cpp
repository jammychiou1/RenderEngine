#include "CameraController.h"

#include <glm/gtc/constants.hpp>
#include <glm/gtx/rotate_vector.hpp>

CameraController::CameraController(Camera* camera, glm::vec3 pos, glm::vec2 lng_lat, Terrain* terrain) :
        _camera(camera), _terrain(terrain), _pos(pos), _vel(), _lng_lat(lng_lat), _ang_vel() {}

CameraController::~CameraController() {}

void CameraController::update(float t) {
    _lng_lat += _ang_vel;
    if (_lng_lat.y > glm::half_pi<float>()) _lng_lat.y = glm::half_pi<float>();
    if (_lng_lat.y < -glm::half_pi<float>()) _lng_lat.y = -glm::half_pi<float>();

    glm::vec3 up(0, 1, 0);
    glm::vec3 forward = glm::rotate(glm::vec3(0, 0, -1), _lng_lat.x, up);
    glm::vec3 right = glm::cross(forward, up);

    _pos += glm::rotate(_vel, _lng_lat.x, up) * 10.0f * t;
    _pos.y = _terrain->getHeight(_pos.x, _pos.z) + 2;

    up = rotate(up, _lng_lat.y, right);
    forward = rotate(forward, _lng_lat.y, right);

    _camera->setPos(_pos);
    _camera->setRot(forward, up);
}
