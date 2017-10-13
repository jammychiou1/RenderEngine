#include "Display.h"

#include <glm/gtc/constants.hpp>

#include <string>
#include <iostream>
#include <exception>

Display::Display(const std::string& title, int width, int height) {
//    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
//    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
//    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
//    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
//    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
//    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
//    _window = glfwCreateWindow(mode->width, mode->height, "My Title", monitor, NULL);

    //Window hints
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

    //Create window
    _window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (_window == nullptr) {
        throw std::runtime_error("Error: Window was not created.");
    }

    //Window settings
    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);
    glfwSwapInterval(1);

    //Set size
    glfwGetFramebufferSize(_window, &_width, &_height);

    glfwShowWindow(_window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Error: GLEW could not be initialized." << glewGetErrorString(err) << std::endl;
        throw std::runtime_error("Error: GLEW could not be initialized.");
    }
}

Display::~Display() {
    glfwDestroyWindow(_window);
}

//void Display::init() {
//////    _w = _s = _a = _d = _space = _shift = false;
////    glfwSetKeyCallback(_window, Display::_keyCallBack);
////    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
////    glfwSetCursorPosCallback(_window, Display::_cursorPosCallBack);
//    glfwSwapInterval(1);
//}
//
//void Display::makeCurrent() {
//    if (_window == NULL) {
//        std::cerr << "Error: Window was not created." << std::endl;
//    }
//    else {
//        glfwMakeContextCurrent(_window);
//    }
//}

bool Display::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void Display::clearScreen(float R, float G, float B, float A) {
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//void Display::updateControls(float t) {
//    glm::vec3 vel;
//    glm::vec2 ang_vel;
//
//    if (_a != _d) {
//        if (_a) vel.x = -1;
//        else vel.x = 1;
//    }
//    else vel.x = 0;
//
//    if (_shift != _space) {
//        if (_shift) vel.y = -1;
//        else vel.y = 1;
//    }
//    else vel.y = 0;
//
//    if (_w != _s) {
//        if (_w) vel.z = -1;
//        else vel.z = 1;
//    }
//    else vel.z = 0;
//
//    if (glm::length(vel) > 0.01) {
//        vel = glm::normalize(vel);
//    }
//
//    ang_vel.x = -(_cursor_x2 - _cursor_x1) / 1000 * glm::half_pi<float>();
//    ang_vel.y = -(_cursor_y2 - _cursor_y1) / 1000 * glm::half_pi<float>();
//
//    _cursor_x1 = _cursor_x2;
//    _cursor_y1 = _cursor_y2;
//
//    _controller->setVel(vel);
//    _controller->setAngVel(ang_vel);
//
//    _controller->update(t);
//}

void Display::swapBuffer() {
    glfwSwapBuffers(_window);
}

//void Display::_keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
//    Display* display = (Display*)glfwGetWindowUserPointer(window);
//    if (action == GLFW_PRESS) {
//        if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(window, true);
//        if (key == GLFW_KEY_W) display->_w = true;
//        if (key == GLFW_KEY_S) display->_s = true;
//        if (key == GLFW_KEY_A) display->_a = true;
//        if (key == GLFW_KEY_D) display->_d = true;
//        if (key == GLFW_KEY_SPACE) display->_space = true;
//        if (key == GLFW_KEY_LEFT_SHIFT) display->_shift = true;
//    }
//    if (action == GLFW_RELEASE) {
//        if (key == GLFW_KEY_W) display->_w = false;
//        if (key == GLFW_KEY_S) display->_s = false;
//        if (key == GLFW_KEY_A) display->_a = false;
//        if (key == GLFW_KEY_D) display->_d = false;
//        if (key == GLFW_KEY_SPACE) display->_space = false;
//        if (key == GLFW_KEY_LEFT_SHIFT) display->_shift = false;
//    }
//
//}
//
//void Display::_cursorPosCallBack(GLFWwindow* window, double x, double y) {
//    //std::cout << x << " " << y << std::endl;
//    Display* display = (Display*)glfwGetWindowUserPointer(window);
//    display->_cursor_x2 = x;
//    display->_cursor_y2 = y;
////    display->_camera->lng = -(x - display->_cursor_x0) / 1000 * 3.1415926 / 2;
////    display->_camera->lat = -(y - display->_cursor_y0) / 1000 * 3.1415926 / 2;
//}
