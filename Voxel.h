//
// Created by Konrad on 12/24/2024.
//

#ifndef VOXEL_GAME_OPENGL_VOXEL_H
#define VOXEL_GAME_OPENGL_VOXEL_H
#include "Shader.h"
#include "glm/detail/type_vec2.hpp"
#include <glm/vec3.hpp>
#include <vector>

struct Vertex{
    glm::vec3 pos;
    glm::vec3 color;
    glm::vec2 texture;
};

const double voxelUnit = 0.3;
const std::vector<Vertex> SQUARE = {{glm::vec3(voxelUnit,voxelUnit,0), glm::vec3(1,0,0), glm::vec2(1,1)},
                                    {glm::vec3(voxelUnit,-voxelUnit,0), glm::vec3(0,1,0), glm::vec2(1,0)},
                                    {glm::vec3(-voxelUnit,-voxelUnit,0), glm::vec3(0,0,1), glm::vec2(0,0)},
                                    {glm::vec3(-voxelUnit,voxelUnit,0), glm::vec3(1,1,0), glm::vec2(0,1)}};

const std::vector<int> SQUARE_INDICES = {0,1,3,1,2,3};

class Voxel {
public:
    Voxel(glm::vec3 pos, Shader shd);
    virtual void draw();
private :
    void generateVertices();
    Shader shader;
    glm::vec3 position;
    std::vector<Vertex> vertices;
    std::vector<int> indices;
    unsigned int VBO, VAO, EBO;
};



#endif //VOXEL_GAME_OPENGL_VOXEL_H
