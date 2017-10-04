#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

namespace JMChuRE {
    class RenderObject
    {
        public:
            RenderObject(Mesh* mesh, Material* material);
            virtual ~RenderObject();
            void render() {

            }

        private:
            Mesh* _mesh;
            Material* _material;
    };
}
#endif // RENDEROBJECT_H
