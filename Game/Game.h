#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GameDefaults.h"
#include "../utils/utils.h"

class Game {
private:
    GLFWwindow *window;
    GLvoid createWindow(const char *title, GLboolean fullscreen);
    static GLvoid loadGLAD();
    static GLvoid frameBufferSizeCallback(GLFWwindow *window, GLint width, GLint height);
    GLvoid setCallbacks() const;
public:
    explicit Game(const char *title = DEFAULT_TITLE, GLboolean fullscreen = FULL_SCREEN);
    NODISCARD GLFWwindow *getWindow() const;
    GLvoid run() const;
    GLvoid shut() const;
};
