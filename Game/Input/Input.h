#pragma once

#include <GLFW/glfw3.h>
#include "../../utils/utils.h"

class Input {
private:
    static GLFWwindow *targetWindow;
    static GLfloat prevXPos;
    static GLfloat prevYPos;
    static GLfloat xOffset;
    static GLfloat yOffset;
    static GLboolean firstMove;
public:
    static GLvoid setWindow(GLFWwindow *window);
    NODISCARD static bool getKeyPress(GLint key);
    NODISCARD static GLfloat getXOffset();
    NODISCARD static GLfloat getYOffset();
    static GLvoid mouseCallback(GLFWwindow *window, GLdouble xPos, GLdouble yPos);
};
