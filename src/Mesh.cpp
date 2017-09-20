#include "Mesh.h"

#include <vector>

Mesh::Mesh() : _draw_cnt(0) {
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    {
        glGenBuffers(1, &_VBO);
        glGenBuffers(1, &_IBO);
    }
    glBindVertexArray(0);
}

void Mesh::bufferData(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices) {

//    for (int i = 0; i < vert_cnt; i++) {
//        for (int j = 0; j < 8; j++) {
//            std::cout << ((float*)verts)[8 * i + j] << " ";
//        }
//        std::cout << std::endl;
//    }

    _draw_cnt = indices.size();

    glBindVertexArray(_VAO);
    {
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec3));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3) + sizeof(glm::vec2)));

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _draw_cnt * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    }
    glBindVertexArray(0);

//    std::vector<glm::vec3> verts_n;
//
//    for (int i = 0; i < vert_cnt; i++) {
//        verts_n.push_back(verts[i].position);
//        verts_n.push_back(verts[i].position + 0.25f * verts[i].normal);
//    }

//    glGenVertexArrays(1, &_VAO_n);

//    glBindVertexArray(_VAO_n);
//    {
//        glGenBuffers(1, &_VBO_n);
//
//        glBindBuffer(GL_ARRAY_BUFFER, _VBO_n);
//        glBufferData(GL_ARRAY_BUFFER, verts_n.size() * sizeof(glm::vec3), &verts_n[0], GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    }
//    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &_VBO);
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_IBO);
//    glDeleteBuffers(1, &_VBO_n);
//    glDeleteVertexArrays(1, &_VAO_n);
}

void Mesh::draw() {
    glBindVertexArray(_VAO);
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
        glDrawElements(GL_TRIANGLES, _draw_cnt, GL_UNSIGNED_INT, 0);
    }
    glBindVertexArray(0);
}

//void Mesh::drawNormals() {
//    glBindVertexArray(_VAO_n);
//    {
//        glDrawArrays(GL_LINES, 0, _verts_cnt*2);
//    }
//    glBindVertexArray(0);
//}
