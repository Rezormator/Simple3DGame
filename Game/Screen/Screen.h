#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../../utils/utils.h"

class Screen {
private:
    static GLfloat width;
    static GLfloat height;
    static glm::vec4 backgroundColor;
    static GLboolean initialized;
public:
    static GLvoid update(GLint width, GLint height, const glm::vec3 &color);
    static GLvoid setBackgroundColor(const glm::vec3 &color);
    NODISCARD static GLfloat getWidth();
    NODISCARD static GLfloat getHeight();
    NODISCARD static GLfloat getAspectRatio();
    static GLvoid clear();
};
