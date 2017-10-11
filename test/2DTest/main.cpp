#include <chrono>
#include <iostream>
#include "Canvas2D.h"

void run() {
    std::cout << "Hi" << std::endl;
}

int main() {
    JMChuRE::Canvas2D::init();
    JMChuRE::Canvas2D canvas("Test", 960, 640);
    canvas.start(run);
//    std::chrono::system_clock::time_point now = std::chrono::system_clock::now(), start = std::chrono::system_clock::now();
//    float time = std::chrono::duration_cast<std::chrono::microseconds>(now - start).count() / 1e6;
//    while () {
//        now = std::chrono::system_clock::now();
//        time = std::chrono::duration_cast<std::chrono::microseconds>(now - start).count() / 1e6;
//    }
    JMChuRE::Canvas2D::terminate();
}
