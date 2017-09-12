#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>
#include <vector>

#include "Vertex.h"

class OBJLoader
{
    public:
        static void loadFile(const std::string& file_name, std::vector<Vertex>& verts, std::vector<unsigned int>& indices);
};

#endif // OBJLOADER_H
