#include "Canvas2D.h"

namespace JMChuRE {
    Canvas2D::Canvas2D(const std::string& title, int width, int height) : _display(title, width, height) {}

    Canvas2D::~Canvas2D() {
    }
}
