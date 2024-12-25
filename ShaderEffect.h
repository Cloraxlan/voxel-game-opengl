//
// Created by Konrad on 12/25/2024.
//

#ifndef VOXEL_GAME_OPENGL_SHADEREFFECT_H
#define VOXEL_GAME_OPENGL_SHADEREFFECT_H


class ShaderEffect{
public:
    virtual void applyEffect(unsigned int shaderProgram) = 0;
};

class CircularRotationEffect : public ShaderEffect{
public:
    void applyEffect(unsigned int shaderProgram) override;

};

class FlatPerspectiveEffect : public ShaderEffect{
public:
    void applyEffect(unsigned int shaderProgram) override;
};

#endif //VOXEL_GAME_OPENGL_SHADEREFFECT_H
