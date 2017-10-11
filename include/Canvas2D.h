#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

#include "Display.h"

namespace JMChuRE {
    class Canvas2D
    {
        public:
            Canvas2D(const std::string& title, int width, int height);
            virtual ~Canvas2D();

            bool static init() {
                if (!glfwInit()) {
                    std::cerr << "Error: GLFW could not be initialized." << std::endl;
                    return false;
                }
                return true;
            }

            void start(void(*run)()) {
                while (!_display.shouldClose()) {
                    run();
                    _display.swapBuffer();
                    glfwPollEvents();
                }
            }

            void static terminate() {
                glfwTerminate();
            }

        private:
            Display _display;
    };
}

#endif // CANVAS2D_H
