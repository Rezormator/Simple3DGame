cmake_minimum_required(VERSION 3.28)
project(Simple3DGame)

set(CMAKE_CXX_STANDARD 20)

set(SRC D:/OpenGL/includes)
set(LIBS D:/OpenGL/lib)

link_directories(${LIBS})
include_directories(${SRC})

set(SOURCE_FILES ${SRC}/glad/glad.c
        ${SRC}/stb/stb_image.cpp
        Application/Application.h
        Application/Application.cpp
        Game/Game.h
        Game/Game.cpp
        utils/utils.h
        Game/Screen/Screen.h
        Game/Screen/Screen.cpp
        Game/Camera/Camera.h
        Game/Camera/Camera.cpp
        Game/GameObject.h
        Game/GameObject.cpp
        Game/Texture/Texture2D.cpp
        Game/Texture/Texture2D.cpp
        Game/Objects/Rectangle/Rectangle.h
        Game/Objects/Rectangle/Rectangle.cpp
        Game/Shader/Shader.h
        Game/Shader/Shader.cpp
        Dispose/IDisposable.h)

add_executable(Simple3DGame ${SOURCE_FILES} main.cpp)
target_link_libraries(Simple3DGame glfw3 opengl32)