#pragma once

#include <glad/glad.h>
#include <map>
#include <string>
#include "../Camera/Camera.h"
#include "../Shader/Shader.h"
#include "../Texture2D/Texture2D.h"
#include "../Objects/Cube/Cube.h"
#include "../Objects/Rectangle/Rectangle.h"

class Scene {
public:
    static Camera *camera;
    static Shader *shader;
    static std::map<std::string, Texture2D *> textures;
    static std::map<std::string, Rectangle *> rectangles;
    static std::map<std::string, Cube *> cubes;
public:
    static GLvoid create();
    static GLvoid draw();
    static GLvoid despose();
};
