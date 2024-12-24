cmake_minimum_required(VERSION 3.26)
project(voxel-game-opengl)
set(CMAKE_CXX_STANDARD 17)
add_executable(voxel-game-opengl main.cpp glad.c
        Shader.h
        Shader.cpp
        Voxel.h
        Voxel.cpp
        stb_image.h
)
target_include_directories(voxel-game-opengl PUBLIC F:/mingw/include)
add_subdirectory(glfw)
add_subdirectory(glm)
target_link_libraries(voxel-game-opengl glfw glm)