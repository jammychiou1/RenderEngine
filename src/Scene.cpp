#include "Scene.h"

#include <iostream>
#include "helper/ShaderSrcLoader.h"

namespace JMChuRE {
    Scene::Scene() {
        std::cout << "shader src loading ok" << std::endl;
        std::string vs_src = ShaderSrcLoader::getShaderSrc("./res/test.vs");
        std::string fs_src = ShaderSrcLoader::getShaderSrc("./res/general.fs");
        _program.build(vs_src, fs_src);
    }

    Scene::~Scene() {}

    void Scene::render() {
        if (_camera) _program.render(_camera, _light_pos, _render_objs);
    }
}
