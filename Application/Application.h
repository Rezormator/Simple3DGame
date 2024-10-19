#pragma once

#include "../Game/Game.h"

class Application {
private:
    static Game *game;
    static GLvoid initielizeGLFW();
public:
    static GLvoid crate();
    static GLvoid run();
    static GLvoid shut();
};
