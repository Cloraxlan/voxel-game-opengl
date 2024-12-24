//
// Created by Konrad on 12/24/2024.
//

#ifndef VOXEL_GAME_OPENGL_SHADER_H
#define VOXEL_GAME_OPENGL_SHADER_H


#include <string>
#include <vector>

class Shader {
public:
    void addVertexShader(std::string path);
    void addFragShader(std::string path);
    void addTexture(std::string path, std::string key);
    void compile();
    void apply();
    unsigned int getShaderProgram();
private:
    std::string readFromFile(std::string path);
    int vertexShader = -1;
    int fragmentShader = -1;
    int shaderProgram = -1;
    std::vector<unsigned int> textures;
    std::vector<std::string> texture_keys;
};




#endif //VOXEL_GAME_OPENGL_SHADER_H
