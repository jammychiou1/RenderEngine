#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Vertex.h"
class Terrain
{
    public:
        Terrain(int size, float length, float height, int level, int seed, float rate);
        virtual ~Terrain();
        std::vector<Vertex>& getVertices() {return _vertices;}
        std::vector<unsigned int>& getIndices() {return _indices;}
        float getHeight(float pos_x, float pos_y);

    private:
        std::vector<std::vector<float>> _grid;
        std::vector<Vertex> _vertices;
        std::vector<unsigned int> _indices;
        int _size;
        float _length;
};

#endif // TERRAIN_H
