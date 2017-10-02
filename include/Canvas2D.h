#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <GLFW/glfw3.h>

namespace JMChuRE {
    class Canvas2D
    {
        public:
            Canvas2D(int width, int height);
            virtual ~Canvas2D();

            bool static init() {
                if (!glfwInit()) {
                    std::cerr << "Error: GLFW could not be initialized." << std::endl;
                    return false;
                }
                return true;
            }
            void static terminate() {
                glfwTerminate();
            }
        private:
            _window
    };
}

#endif // CANVAS2D_H
