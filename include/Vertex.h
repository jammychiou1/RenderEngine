#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

struct Vertex
{
    public:
        Vertex(glm::vec3 position = glm::vec3(), glm::vec2 tex_coord = glm::vec2(), glm::vec3 normal = glm::vec3()) : position(position), tex_coord(tex_coord), normal(normal) {}
        glm::vec3 position;
        glm::vec2 tex_coord;
        glm::vec3 normal;
};

#endif // VERTEX_H
