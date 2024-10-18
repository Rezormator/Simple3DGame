#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>

class Screen {
private:
    static constexpr GLint UNINITIALIZED_SCREEN_SIZE = -1;
    static GLint screeenWidth;
    static GLint screeenHiegth;
    static glm::vec4 backgroundColor;
public:
    static GLvoid setScreenSize(GLint width, GLint hiegth);
    static GLvoid setBackgroundColor(const glm::vec3 &color);
    static GLvoid clear();
    static GLfloat getAspectRatio();
};
