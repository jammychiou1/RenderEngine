#include "Canvas2D.h"

#include <iostream>

namespace JMChuRE {
    Canvas2D::Canvas2D(const std::string& title, int width, int height, RenderEngineBase* reb) : _display(title, width, height), _reb(reb) {
        std::cout << "canvas ok" << std::endl;
    }

    Canvas2D::~Canvas2D() {
    }
}
