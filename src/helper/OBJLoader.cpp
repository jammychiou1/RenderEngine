#include "helper/OBJLoader.h"

#include <glm/glm.hpp>

#include <tuple>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>

void OBJLoader::loadFile(const std::string& file_name, std::vector<Vertex>& verts, std::vector<unsigned int>& indices) {
    std::ifstream file;
    file.open(file_name.c_str());

    std::string line, word;

    std::vector<glm::vec3> pos;
    std::vector<glm::vec2> tex_coord;
    std::vector<glm::vec3> norm;

    std::map< std::tuple<int, int, int>, unsigned int> M;

    if(file.is_open()) {
        while(file.good()) {
            std::stringstream ss;
            getline(file, line);
            ss << line;
            ss >> word;
            if (word == "v") {
                glm::vec3 tmp(0);
                ss >> tmp.x >> tmp.y >> tmp.z;
                pos.push_back(tmp);
            }
            else if (word == "vt") {
                glm::vec2 tmp(0);
                ss >> tmp.x >> tmp.y;
                tex_coord.push_back(tmp);
            }
            else if (word == "vn") {
                glm::vec3 tmp(0);
                ss >> tmp.x >> tmp.y >> tmp.z;
                norm.push_back(tmp);
            }
            else if (word == "s") {
                break;
            }
        }
        while(file.good()) {
            std::stringstream ss;
            getline(file, line);
            ss << line;
            ss >> word;
            if (word == "f") {
                for (int i = 0; i < 3; i++) {
                    int v, vt, vn;
                    char c;
                    ss >> v >> c >> vt >> c >> vn;
                    std::tuple<int, int, int> tmp(v-1, vt-1, vn-1);
                    if (!M.count(tmp)) {
                        int sz = M.size();
                        M[tmp] = sz;
//                        std::cout << M[tmp] << std::endl;
                    }
                    indices.push_back(M[tmp]);
                }
            }
        }
    }
    else {
		std::cerr << "Error: Unable to load obj file (" << file_name << ")" << std::endl;
    }

    file.close();

//    std::cout << M.size() << std::endl;
//    for (std::map< std::tuple<int, int, int>, unsigned short>::iterator itr = M.begin(); itr != M.end(); itr++) {
//        std::tuple<int, int, int> vert = (*itr).first;
//        unsigned short ind = (*itr).second;
//        std::cout << ind << ": " << std::get<0>(vert) << " " << std::get<1>(vert) << " " << std::get<2>(vert) << std::endl;
//    }

    verts.resize(M.size());
    for (std::map< std::tuple<int, int, int>, unsigned int>::iterator itr = M.begin(); itr != M.end(); itr++) {
        std::tuple<int, int, int> vert = (*itr).first;
        unsigned int ind = (*itr).second;
        verts[ind] = Vertex(pos[std::get<0>(vert)], tex_coord[std::get<1>(vert)], norm[std::get<2>(vert)]);
    }
//
//    for (int i = 0; i < verts.size(); i++) {
//        Vertex v = verts[i];
//        std::cout << i << "    ";
//        std::cout << "pos:" << v.position.x << " " << v.position.y << " " << v.position.z << "    ";
//        std::cout << "uv:" << v.tex_coord.x << " " << v.tex_coord.y << "    ";
//        std::cout << "norm:" << v.normal.x << " " << v.normal.y << " " << v.normal.z << std::endl;
//    }
}
