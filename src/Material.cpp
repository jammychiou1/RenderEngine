#include "Material.h"
namespace JMChuRE {
    Material::Material(bool use_lighting, Texture* texture, glm::vec4 color) : _use_lighting(use_lighting), _texture(texture), _color(color) {
    }

    Material::~Material() {}
}
