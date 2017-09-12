#include "helper/ShaderSrcLoader.h"

#include <fstream>
#include <iostream>

std::string ShaderSrcLoader::getShaderSrc(const std::string& file_name) {
    std::ifstream file;
    file.open(file_name.c_str());

    std::string output;
    std::string line;

    if(file.is_open()) {
        while(file.good()) {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else {
		std::cerr << "Error: Unable to load shader (" << file_name << ")" << std::endl;
    }

    file.close();
    return output;
}
