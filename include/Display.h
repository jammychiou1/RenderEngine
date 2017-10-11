#ifndef DISPLAY_H
#define DISPLAY_H

#include <GLFW/glfw3.h>

#include <string>

#include "CameraController.h"

class Display
{
    public:
        Display(const std::string& title, int width, int height);
        virtual ~Display();
//        void makeCurrent();
//        void init();
        bool shouldClose();
//        void setController(CameraController* controller) {_controller = controller; glfwGetCursorPos(_window, &_cursor_x1, &_cursor_y1); glfwGetCursorPos(_window, &_cursor_x2, &_cursor_y2);}
        void clearScreen(float R, float G, float B, float A);
//        void updateControls(float t);
        void swapBuffer();
        int getWidth() {return _width;}
        int getHeight() {return _height;}

    private:
        GLFWwindow* _window;

        int _width;
        int _height;

//        bool _w, _s, _a, _d, _space, _shift;
//        double _cursor_x1, _cursor_y1;
//        double _cursor_x2, _cursor_y2;
//
//        CameraController* _controller;
//
//        static void _keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
//        static void _cursorPosCallBack(GLFWwindow* window, double x, double y);
};

#endif // DISPLAY_H
