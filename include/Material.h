#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <glm/glm.hpp>
#include "Texture.h"

namespace JMChuRE {
    class Material
    {
        public:
            Material(bool use_lighting, bool use_texture, std::string texture_file, glm::vec3 color);
            Material();
            virtual ~Material();

            bool get_use_lighting() const {
                return _use_lighting;
            }
            Texture* get_texture() const {
                return _texture;
            }
            glm::vec3 get_default_color() const {
                return _default_color;
            }
        private:
            bool _use_lighting;
            Texture* _texture;
            glm::vec3 _default_color;
    };
}
#endif // MATERIAL_H
