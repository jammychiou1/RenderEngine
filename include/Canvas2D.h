#ifndef CANVAS2D_H
#define CANVAS2D_H

#include <iostream>
#include <string>

#include "Scene.h"
#include "Display.h"

namespace JMChuRE {
    class RenderEngineBase {
        public:
            virtual void load() = 0;
            virtual void run() = 0;
    };

    class Canvas2D
    {
        public:
            Canvas2D(const std::string& title, int width, int height, RenderEngineBase* reb);
            virtual ~Canvas2D();

            bool static init() {
                if (!glfwInit()) {
                    std::cerr << "Error: GLFW could not be initialized." << std::endl;
                    return false;
                }
                return true;
            }

            void start() {
                std::cout << "ok" << std::endl;
                _reb->load();
                while (!_display.shouldClose()) {
                    _reb->run();
                    _display.clearScreen(1, 1, 1, 0);
                    if (_scene) _scene->render();
                    _display.swapBuffer();
                    glfwPollEvents();
                }
            }

            void static terminate() {
                glfwTerminate();
            }

            void set_scene(Scene* scene) {_scene = scene;}

        private:
            Scene* _scene;
            Display _display;
            RenderEngineBase* _reb;
    };
}

#endif // CANVAS2D_H
