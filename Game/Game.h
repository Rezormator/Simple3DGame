#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../utils/utils.h"

constexpr auto DEFAULT_TITLE = "Simple3DGame";
constexpr GLboolean FULL_SCREEN = true;
constexpr glm::vec3 DEFAULT_COLOR = {0.3f, 0.6f, 0.6f};

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
