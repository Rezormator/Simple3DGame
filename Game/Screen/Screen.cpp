#include "Screen.h"
#include "iostream"

GLint Screen::screeenWidth = UNINITIALIZED_SCREEN_SIZE;
GLint Screen::screeenHiegth = UNINITIALIZED_SCREEN_SIZE;
glm::vec4 Screen::backgroundColor;

GLvoid Screen::setScreenSize(const GLint width, const GLint hiegth) {
    if (width <= 0 || hiegth <= 0)
        std::cout << "SCREEN_SIZE_ERROR" << std::endl;
    screeenWidth = width;
    screeenHiegth = hiegth;
}

GLvoid Screen::setBackgroundColor(const glm::vec3 &color) {
    backgroundColor = glm::vec4(color, 1.0f);
}

GLvoid Screen::clear() {
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLfloat Screen::getAspectRatio() {
    if (screeenWidth == UNINITIALIZED_SCREEN_SIZE || screeenHiegth == UNINITIALIZED_SCREEN_SIZE)
        std::cout << "SCREEN_UNITILIZED_ERROR" << std::endl;
    return static_cast<GLfloat>(screeenWidth) / static_cast<GLfloat>(screeenHiegth);
}


