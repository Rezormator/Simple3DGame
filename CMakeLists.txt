cmake_minimum_required(VERSION 3.28)
project(Simple3DGame)

set(CMAKE_CXX_STANDARD 20)

set(SRC D:/OpenGL/includes)
set(LIBS D:/OpenGL/lib)

link_directories(${LIBS})
include_directories(${SRC})

set(SOURCE_FILES ${SRC}/glad/glad.c
        ${SRC}/stb/stb_image.cpp
        utils/utils.h
        Error/Error.h
        Error/Error.cpp
        Game/Game.h
        Game/Game.cpp
        Game/GameDefaults.h
        Application/Application.h
        Application/Application.cpp
        stb/stb_image.cpp
        stb/stb_image.h
        Game/GameObject/GameObject.h
        Game/GameObject/GameObject.cpp
        Game/GameObject/GameObjectDefaults.h
)

add_executable(Simple3DGame ${SOURCE_FILES} main.cpp)
target_link_libraries(Simple3DGame glfw3 opengl32)