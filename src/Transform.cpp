#include "Transform.h"

Transform::Transform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scl) : _pos(pos), _rot(rot), _scl(scl) {}

Transform::~Transform() {}

glm::mat4 Transform::getModel() const {
    glm::mat4 pos_mat = glm::translate(_pos);
    glm::mat4 rot_mat_X = glm::rotate(_rot.x, glm::vec3(1,0,0));
    glm::mat4 rot_mat_Y = glm::rotate(_rot.y, glm::vec3(0,1,0));
    glm::mat4 rot_mat_Z = glm::rotate(_rot.z, glm::vec3(0,0,1));
    glm::mat4 scl_mat = glm::scale(_scl);
    return pos_mat * rot_mat_Z * rot_mat_Y * rot_mat_X * scl_mat;
}

glm::vec3& Transform::getPos() {return _pos;}
glm::vec3& Transform::getRot() {return _rot;}
glm::vec3& Transform::getScl() {return _scl;}
