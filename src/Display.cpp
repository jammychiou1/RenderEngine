#include "Display.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/constants.hpp>

#include <string>
#include <iostream>

Display::Display(const std::string& title) {
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    glfwWindowHint(GLFW_SAMPLES, 8);
    _window = glfwCreateWindow(mode->width, mode->height, "My Title", monitor, NULL);
    glfwGetWindowSize(_window, &_width, &_height);
    glfwSetWindowUserPointer(_window, this);
}

Display::~Display() {
    glfwDestroyWindow(_window);
}

void Display::init() {
    _flag_close = false;
    _w = _s = _a = _d = _space = _shift = false;
    glfwSetKeyCallback(_window, Display::_keyCallBack);
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(_window, Display::_cursorPosCallBack);
    //glfwGetCursorPos(_window, &_cursor_x, &_cursor_y);
}

void Display::makeCurrent() {
    if (_window == NULL) {
        std::cerr << "Error: Window was not created." << std::endl;
    }
    else {
        glfwMakeContextCurrent(_window);
    }
}

bool Display::shouldClose() {
    return glfwWindowShouldClose(_window) || _flag_close;
}

void Display::clearScreen(float R, float G, float B, float A) {
    glClearColor(R, G, B, A);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::updateControls() {
    glm::vec3 vel;
    glm::vec2 ang_vel;

    if (_a != _d) {
        if (_a) vel.x = -1;
        else vel.x = 1;
    }
    else vel.x = 0;

    if (_shift != _space) {
        if (_shift) vel.y = -1;
        else vel.y = 1;
    }
    else vel.y = 0;

    if (_w != _s) {
        if (_w) vel.z = -1;
        else vel.z = 1;
    }
    else vel.z = 0;

    if (glm::length(vel) > 0.01) {
        vel = glm::normalize(vel) * 0.1f;
    }

    ang_vel.x = -(_cursor_x2 - _cursor_x1) / 1000 * glm::half_pi<float>();
    ang_vel.y = -(_cursor_y2 - _cursor_y1) / 1000 * glm::half_pi<float>();

    _cursor_x1 = _cursor_x2;
    _cursor_y1 = _cursor_y2;

    _controller->setVel(vel);
    _controller->setAngVel(ang_vel);

    _controller->update();
}

void Display::swapBuffer() {
    glfwSwapBuffers(_window);
}

void Display::_keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Display* display = (Display*)glfwGetWindowUserPointer(window);
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_ESCAPE) display->_flag_close = true;
        if (key == GLFW_KEY_W) display->_w = true;
        if (key == GLFW_KEY_S) display->_s = true;
        if (key == GLFW_KEY_A) display->_a = true;
        if (key == GLFW_KEY_D) display->_d = true;
        if (key == GLFW_KEY_SPACE) display->_space = true;
        if (key == GLFW_KEY_LEFT_SHIFT) display->_shift = true;
    }
    if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W) display->_w = false;
        if (key == GLFW_KEY_S) display->_s = false;
        if (key == GLFW_KEY_A) display->_a = false;
        if (key == GLFW_KEY_D) display->_d = false;
        if (key == GLFW_KEY_SPACE) display->_space = false;
        if (key == GLFW_KEY_LEFT_SHIFT) display->_shift = false;
    }

}

void Display::_cursorPosCallBack(GLFWwindow* window, double x, double y) {
    //std::cout << x << " " << y << std::endl;
    Display* display = (Display*)glfwGetWindowUserPointer(window);
    display->_cursor_x2 = x;
    display->_cursor_y2 = y;
//    display->_camera->lng = -(x - display->_cursor_x0) / 1000 * 3.1415926 / 2;
//    display->_camera->lat = -(y - display->_cursor_y0) / 1000 * 3.1415926 / 2;
}
