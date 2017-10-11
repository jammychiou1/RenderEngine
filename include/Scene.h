#ifndef SCENE_H
#define SCENE_H

#include "RenderObject.h"
#include "Camera.h"

namespace JMChuRE {
    class Scene
    {
        public:
            Scene();
            virtual ~Scene();
            void add_render_object(JMChuRE::RenderObject* render_object) {
                _render_objs.push_back(render_object);
            }
            Camera* get_camera() {return _camera;}
            void set_camera(Camera* camera) {_camera = camera;}
            glm::vec3 get_light_pos() {return _light_pos;}
            void set_light_pos(glm::vec3 light_pos) {_light_pos = light_pos;}

        private:
            std::vector<RenderObject*> _render_objs;
            Camera* _camera;
            glm::vec3 _light_pos;
            Program _program;
    };
}

#endif // SCENE_H
