#ifndef SCENE_H
#define SCENE_H

namespace JMChuRE {
    class Scene
    {
        public:
            Scene();
            virtual ~Scene();

        private:
            std::vector<RenderObject*> _render_objs;
            Camera* _camera;
            glm::vec3 _light_pos;
    };
}

#endif // SCENE_H
