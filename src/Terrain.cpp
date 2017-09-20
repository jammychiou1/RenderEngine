#include "Terrain.h"

#include <glm/gtc/noise.hpp>
#include <glm/glm.hpp>

Terrain::Terrain(int size, float length, float height, int level, int seed, float rate) : _size(size), _length(length) {
    _grid.resize(size);
    for (int i = 0; i < size; i++) {
        _grid[i].resize(size);
    }

    float amp = height;
    float freq = 0.005;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            _grid[x][y] = 0;
        }
    }
    for (int i = 1; i <= level; i++) {
        for (int x = 0; x < size; x++) {
            float pos_x = (x*2.0/size - 1)*length;
            for (int y = 0; y < size; y++) {
                float pos_y = (y*2.0/size - 1)*length;
                _grid[x][y] += glm::perlin(glm::vec3(pos_x*freq, pos_y*freq, (seed+i)*10)) * amp;
            }
        }
        amp *= rate;
        freq *= 2;
    }
    for (int y = 0; y < size; y++) {
        float pos_y = (y*2.0/size - 1)*length;
        for (int x = 0; x < size; x++) {
            float pos_x = (x*2.0/size - 1)*length;
            if (x == size-1 || y == size-1) {
                _vertices.push_back(Vertex(
                    glm::vec3(pos_x, _grid[x][y], pos_y),
                    glm::vec2(pos_x*0.25, pos_y*0.25),
                    glm::vec3(0, 1, 0)
                ));
            }
            else {
                glm::vec3 a(2.0/size*length, _grid[x+1][y]-_grid[x][y], 0);
                glm::vec3 b(0, _grid[x][y+1]-_grid[x][y], 2.0/size*length);
                _vertices.push_back(Vertex(
                    glm::vec3(pos_x, _grid[x][y], pos_y),
                    glm::vec2(pos_x*0.25, pos_y*0.25),
                    glm::normalize(glm::cross(b, a))
                ));
            }
        }
    }
    for (int y = 0; y < size-1; y++) {
        for (int x = 0; x < size-1; x++) {
            _indices.push_back(x + y*size);
            _indices.push_back(x + (y+1)*size);
            _indices.push_back((x+1) + (y+1)*size);
            _indices.push_back(x + y*size);
            _indices.push_back((x+1) + (y+1)*size);
            _indices.push_back((x+1) + y*size);
        }
    }
}

Terrain::~Terrain() {}

float Terrain::getHeight(float pos_x, float pos_y) {
    float x = (pos_x/_length+1)*_size/2;
    float y = (pos_y/_length+1)*_size/2;
    if (x < 0 || _size-1 < x || y < 0 || _size-1 < y) {
        return 0;
    }
    float fx = floor(x);
    float fy = floor(y);
    float tx = x-fx;
    float ty = y-fy;
    return glm::mix(glm::mix(_grid[fx][fy], _grid[fx+1][fy], tx), glm::mix(_grid[fx][fy+1], _grid[fx+1][fy+1], tx), ty);
}
