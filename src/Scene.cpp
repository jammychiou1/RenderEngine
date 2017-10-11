#include "Scene.h"

namespace JMChuRE {
    Scene::Scene() {
        std::string vs_src = ShaderSrcLoader::getShaderSrc("./res/test.vs");
        std::string fs_src = ShaderSrcLoader::getShaderSrc("./res/test.fs");
        _program.build(vs_src, fs_src);
    }

    Scene::~Scene() {}
}
