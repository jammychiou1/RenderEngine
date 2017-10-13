#include <chrono>
#include <iostream>
#include <glm/glm.hpp>
#include "Camera.h"
#include "Canvas2D.h"

class MyReb : public JMChuRE::RenderEngineBase {
    public:
        JMChuRE::Canvas2D canvas;
        Camera camera;
        JMChuRE::Scene scene;
        MyReb() : canvas("Test", 960, 640, this), camera(glm::vec3(0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0), 70, 0.01, 200, 960.0/640.0) {
            std::cout << "myreb constructed" << std::endl;

            scene.set_camera(&camera);
            canvas.set_scene(&scene);
        }
        void start() {
            canvas.start();
        }
        void load() {
            std::cout << "Loading" << std::endl;
        }
        void run() {
            std::cout << "Hi" << std::endl;
        }
};

int main() {
    JMChuRE::Canvas2D::init();
    std::cout << "myreb constructing" << std::endl;
    MyReb myreb;
    myreb.start();
    JMChuRE::Canvas2D::terminate();
}
