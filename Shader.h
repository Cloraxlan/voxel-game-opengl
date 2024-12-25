//
// Created by Konrad on 12/24/2024.
//

#ifndef VOXEL_GAME_OPENGL_SHADER_H
#define VOXEL_GAME_OPENGL_SHADER_H


#include <string>
#include <vector>
#include "ShaderEffect.h"

class Shader {
public:
    void addVertexShader(std::string path);
    void addFragShader(std::string path);
    void addTexture(std::string path, std::string key);
    virtual void compile();
    virtual void apply();
    unsigned int getShaderProgram();
private:
    std::string readFromFile(std::string path);
    int vertexShader = -1;
    int fragmentShader = -1;
    int shaderProgram = -1;
    std::vector<unsigned int> textures;
    std::vector<std::string> texture_keys;
};


class ShaderPipeline: public Shader{
public:
    void apply() override;
    void addEffect(ShaderEffect &effect);
private:
    std::vector<ShaderEffect*> effects;
};

class RotationShader : public Shader{
public:
    void apply() override;
private:
    double rotation = 0;
};


#endif //VOXEL_GAME_OPENGL_SHADER_H
