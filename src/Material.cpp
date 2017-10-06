#include "Material.h"
namespace JMChuRE {
    Material::Material(bool use_lighting, bool use_texture, const std::string texture_file, glm::vec3 color) : _use_lighting(use_lighting) {
        if (use_texture) {
            _texture = new Texture(texture_file);
        }
        else {
            _texture = nullptr;
            _default_color = color;
        }
    }

    Material::~Material() {
        delete _texture;
    }
}
