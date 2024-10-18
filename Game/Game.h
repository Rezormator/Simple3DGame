#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include "../utils/utils.h"

class Game {
private:
    static constexpr const char *DEFAULT_TITLE = {"Somple3DGame"};
    static constexpr glm::vec3 DEFAULT_BACKROUND_COLOR = {124.0f, 194.0f, 255.0f};
    static Game *instance;
    GLFWwindow *window;
    const char *title;
    explicit Game(const char *title = DEFAULT_TITLE);
    GLvoid crateWindow();
    GLvoid setCallBacks() const;
    static GLvoid loadGlad();
    static GLvoid frameBufferSizeCallback(GLFWwindow *window, GLint width, GLint height);
public:
    NODISCARD GLFWwindow *getWindow() const;
    GLvoid create();
    static Game *getInstance(const char *title = DEFAULT_TITLE);
    static GLvoid deleteInstance();
    GLvoid run() const;
    GLvoid dispose() const;
};