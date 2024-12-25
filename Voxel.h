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
    glm::vec2 texture;
};

const double voxelUnit = 0.3;
const std::vector<Vertex> SQUARE = {{glm::vec3(voxelUnit,voxelUnit,0),  glm::vec2(1,1)},
                                    {glm::vec3(voxelUnit,-voxelUnit,0),  glm::vec2(1,0)},
                                    {glm::vec3(-voxelUnit,-voxelUnit,0),  glm::vec2(0,0)},
                                    {glm::vec3(-voxelUnit,voxelUnit,0),  glm::vec2(0,1)}};

const std::vector<Vertex> CUBE = {
                                    {glm::vec3(-voxelUnit,-voxelUnit,-voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3(voxelUnit,-voxelUnit,-voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3(voxelUnit,voxelUnit,-voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3(-voxelUnit,voxelUnit,-voxelUnit),  glm::vec2(0,1)},
                                    {glm::vec3(-voxelUnit,-voxelUnit,voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3(voxelUnit,-voxelUnit,voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3(voxelUnit,voxelUnit,voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3(-voxelUnit,voxelUnit,voxelUnit),  glm::vec2(0,1)},

                                    {glm::vec3( -voxelUnit,  voxelUnit, -voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3( -voxelUnit, -voxelUnit, -voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3( -voxelUnit, -voxelUnit,  voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3(-voxelUnit,  voxelUnit,  voxelUnit),  glm::vec2(0,1)},
                                    {glm::vec3(voxelUnit, -voxelUnit, -voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3( voxelUnit,  voxelUnit, -voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3(voxelUnit,  voxelUnit,  voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3(voxelUnit, -voxelUnit,  voxelUnit),  glm::vec2(0,1)},

                                    {glm::vec3(-voxelUnit, -voxelUnit, -voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3(voxelUnit, -voxelUnit, -voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3( voxelUnit, -voxelUnit,  voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3( -voxelUnit, -voxelUnit,  voxelUnit),  glm::vec2(0,1)},
                                    {glm::vec3(voxelUnit,  voxelUnit, -voxelUnit),  glm::vec2(0,0)},
                                    {glm::vec3(-voxelUnit,  voxelUnit, -voxelUnit),  glm::vec2(1,0)},
                                    {glm::vec3(-voxelUnit,  voxelUnit,  voxelUnit),  glm::vec2(1,1)},
                                    {glm::vec3( voxelUnit,  voxelUnit,  voxelUnit),  glm::vec2(0,1)},


                                    };

const std::vector<int> SQUARE_INDICES = {0,1,3,1,2,3};
const std::vector<int> CUBE_INDICES = {
// front and back
0, 3, 2,
2, 1, 0,
4, 5, 6,
6, 7 ,4,
// left and right
11, 8, 9,
9, 10, 11,
12, 13, 14,
14, 15, 12,
// bottom and top
16, 17, 18,
18, 19, 16,
20, 21, 22,
22, 23, 20
};

class Voxel {
public:
    Voxel(std::vector<Vertex> vertices, std::vector<int> indices);
    Voxel();
    Voxel(std::string path);
    virtual void draw(Shader &shd);
private :
    void loadVertices();
    unsigned int VBO, VAO, EBO;
    std::vector<Vertex> vertices;
    std::vector<int> indices;
};



#endif //VOXEL_GAME_OPENGL_VOXEL_H
