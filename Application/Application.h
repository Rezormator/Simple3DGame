#pragma once

#include <glad/glad.h>
#include "../Game/Game.h"

class Application {
private:
    static Game *game;
    static GLvoid initGLFW();
public:
    static GLvoid create(const char *title);
    static GLvoid run();
    static GLvoid terminate();
};