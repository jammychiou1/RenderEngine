#include "Canvas2D.h"

Canvas2D::Canvas2D(int width, int height) {
    if (!glfwInit()) {
        std::cerr << "Error: GLFW could not be initialized." << std::endl;
        glfwTerminate();
        return -1;
    }
}

Canvas2D::~Canvas2D()
{
    //dtor
}
