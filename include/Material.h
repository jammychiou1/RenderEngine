#ifndef MATERIAL_H
#define MATERIAL_H

namespace JMChuRE {
    class Material
    {
        public:
            Material(bool use_lighting, Texture* texture, glm::vec4 color);
            virtual ~Material();
        private:
            bool _use_lighting;
            Texture* _texture;
            glm::vec4 _color;
    };
}
#endif // MATERIAL_H
