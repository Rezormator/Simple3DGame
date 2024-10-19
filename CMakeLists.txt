cmake_minimum_required(VERSION 3.28)
project(Simple3DGame)

set(CMAKE_CXX_STANDARD 20)

set(SRC D:/OpenGL/includes)
set(LIBS D:/OpenGL/lib)

link_directories(${LIBS})
include_directories(${SRC})

set(SOURCE_FILES ${SRC}/glad/glad.c
        ${SRC}/stb/stb_image.cpp
        ${SRC}/stb/stb_image.h
        utils/utils.h
        Error/Error.h
        Error/Error.cpp
        Game/Game.h
        Game/Game.cpp
        Application/Application.h
        Application/Application.cpp
        Game/GameObject/GameObject.h
        Game/GameObject/GameObject.cpp
        Game/Shader/Shader.h
        Game/Shader/Shader.cpp
        Game/Shader/Shader.cpp
        Game/Texture2D/Texture2D.h
        Game/Texture2D/Texture2D.cpp
        Game/Objects/Rectangle/Rectangle.h
        Game/Objects/Rectangle/Rectangle.cpp
        Game/Objects/Rectangle/Rectangle.cpp
        Game/Camera/Camera.cpp
        Game/Objects/Cube/Cube.h
        Game/Objects/Cube/Cube.cpp
)

add_executable(Simple3DGame ${SOURCE_FILES} main.cpp)
target_link_libraries(Simple3DGame glfw3 opengl32)