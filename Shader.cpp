//
// Created by Konrad on 12/24/2024.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void Shader::addVertexShader(std::string path) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string shaderSrc = readFromFile(path);
    const char *c_str = shaderSrc.c_str();
    glShaderSource(vertexShader, 1, &c_str, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        vertexShader = -1;
    }
}

void Shader::addFragShader(std::string path) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string shaderSrc = readFromFile(path);
    const char *c_str = shaderSrc.c_str();
    glShaderSource(fragmentShader, 1, &c_str, NULL);
    glCompileShader(fragmentShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAG::COMPILATION_FAILED\n" << infoLog << std::endl;
        fragmentShader = -1;
    }
}

void Shader::compile() {
    shaderProgram = glCreateProgram();
    if(vertexShader != -1){
        glAttachShader(shaderProgram, vertexShader);
    }
    if(fragmentShader != -1){
        glAttachShader(shaderProgram, fragmentShader);
    }
    glLinkProgram(shaderProgram);
    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
        shaderProgram = -1;
        return;
    }
    if(vertexShader != -1){
        glAttachShader(shaderProgram, vertexShader);
        glDeleteShader(vertexShader);
        vertexShader = -1;
    }
    if(fragmentShader != -1){
        glAttachShader(shaderProgram, fragmentShader);
        glDeleteShader(fragmentShader);
        fragmentShader = -1;
    }
}

void Shader::apply() {
    glUseProgram(getShaderProgram());
    for(int i = 0; i < textures.size(); i++){
        glUniform1i(glGetUniformLocation(shaderProgram, texture_keys[i].c_str()), 0);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[i]);
    }
}

std::string Shader::readFromFile(std::string path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int Shader::getShaderProgram() {
    if(shaderProgram == -1){
        throw std::invalid_argument("No compiled shader program");
    }
    return shaderProgram;
}

void Shader::addTexture(std::string path, std::string key) {
    unsigned int texture;

    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    textures.push_back(texture);
    texture_keys.push_back(key);
}
