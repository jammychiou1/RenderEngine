#ifndef SHADERSRCLOADER_H
#define SHADERSRCLOADER_H

#include <string>

class ShaderSrcLoader
{
    public:
        static std::string getShaderSrc(const std::string& shader_path);
};

#endif // SHADERSRCLOADER_H
