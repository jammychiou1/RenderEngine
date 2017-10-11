#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "Material.h"
#include "Mesh.h"
#include "Transform.h"

namespace JMChuRE {
    class RenderObject
    {
        public:
            RenderObject();
            virtual ~RenderObject();
            Mesh* mesh;
            JMChuRE::Material* material;
            Transform* transform;
    };
}
#endif // RENDEROBJECT_H
