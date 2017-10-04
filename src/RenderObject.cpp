#include "RenderObject.h"

namespace JMChuRE {
    RenderObject::RenderObject(Mesh* mesh, Material* material) : _mesh(mesh), _material(material) {
    }

    RenderObject::~RenderObject() {}
}
