#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <cmath>
#include <iostream>
#include <cstring>
#include <chrono>
#include <vector>

#include "Display.h"
#include "Texture.h"
#include "Vertex.h"
#include "Mesh.h"
#include "UniformMat4.h"
#include "UniformVec3.h"
#include "Transform.h"
#include "Program.h"
#include "helper/OBJLoader.h"
#include "helper/ShaderSrcLoader.h"

//const int width = 1024;
//const int height = 768;

int main() {

    std::string vs_src = ShaderSrcLoader::getShaderSrc("./res/test.vs");
    std::string fs_src = ShaderSrcLoader::getShaderSrc("./res/test.fs");

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    OBJLoader::loadFile("./res/dragon.obj", vertices, indices);

    std::vector<Vertex> vertices_floor({
        Vertex(glm::vec3(-1, 0, 1), glm::vec2(0, 1), glm::vec3(0, 1, 0)),
        Vertex(glm::vec3(1, 0, 1), glm::vec2(1, 1), glm::vec3(0, 1, 0)),
        Vertex(glm::vec3(1, 0, -1), glm::vec2(1, 0), glm::vec3(0, 1, 0)),
        Vertex(glm::vec3(-1, 0, -1), glm::vec2(0, 0), glm::vec3(0, 1, 0)),
    });
    std::vector<unsigned int> indices_floor({0, 1, 2, 0, 2, 3});

    if (!glfwInit()) {
        std::cerr << "Error: GLFW could not be initialized." << std::endl;
        glfwTerminate();
        return -1;
    }

    Display display("OpenGL Test");
    display.makeCurrent();
    display.init();

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Error: GLEW could not be initialized. " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        return -1;
    }

    UniformMat4 u_camera("u_camera");
    UniformMat4 u_transform("u_transform");
    UniformVec3 u_cam_pos("u_cam_pos");
    UniformVec3 u_light_pos("u_light_pos");

    Program program;
    program.addUniform(&u_camera);
    program.addUniform(&u_transform);
    program.addUniform(&u_cam_pos);
    program.addUniform(&u_light_pos);

    program.build(vs_src, fs_src);


    Mesh meshes[2];
    meshes[0].bufferData(vertices, indices);
    meshes[1].bufferData(vertices_floor, indices_floor);

    Transform transforms[2];
    transforms[0].getScl() = glm::vec3(0.4);
    transforms[0].getPos() = glm::vec3(0, 0.5, 0);
    transforms[1].getScl() = glm::vec3(10);

    Texture gold("./res/gold.jpg");
    Texture golden("./res/golden.png");
    Texture white("./res/white.png");
    Texture brick("./res/brick.jpg");
    Texture* textures[2] = {&golden, &gold};

    Camera camera(glm::vec3(), glm::vec3(), glm::vec3(), 70, 0.01, 100, 1.0 * display.getWidth() / display.getHeight());

    CameraController controller(&camera, glm::vec3(0, 0, 1), glm::vec2());

    display.setController(&controller);

    std::chrono::system_clock::time_point then, now, start = std::chrono::system_clock::now();
    double secs;

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!display.shouldClose()) {

        //print fps
        then = now;
        now = std::chrono::system_clock::now();
        std::cout << 1e6 / std::chrono::duration_cast<std::chrono::microseconds>(now - then).count() << std::endl;
        secs = std::chrono::duration_cast<std::chrono::microseconds>(now - start).count() / 1e6;

        //update physics
        display.updateControls();

        //render
        display.clearScreen(0.1, 0.1, 0.3, 0);

        u_camera.setMat(camera.getViewProj());
        u_cam_pos.setVec(camera.getPos());
        u_light_pos.setVec(glm::vec3(0, 3, 5));

        program.use();

        for (int i = 0; i < 2; i++) {
            u_transform.setMat(transforms[i].getModel());
            textures[i]->bindTexture();
            program.update();
            meshes[i].draw();
        }

//        program_n.bindProgram();
//        mesh.drawNormals();

        //update display
        display.swapBuffer();

        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}
