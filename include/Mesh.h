#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>
#include <iostream>

#include "Vertex.h"

class Mesh
{
    public:
        Mesh();
        virtual ~Mesh();
        void bufferData(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
        void draw();
//        void drawNormals();

    private:
        int _draw_cnt;
        GLuint _VAO;
        GLuint _VBO;
        GLuint _IBO;
//        GLuint _VAO_n;
//        GLuint _VBO_n;
};

#endif // MESH_H
