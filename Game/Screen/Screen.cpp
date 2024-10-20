#include "Screen.h"
#include "../../Error/Error.h"

GLfloat Screen::width;
GLfloat Screen::height;
glm::vec4 Screen::backgroundColor;
GLboolean Screen::initialized = false;

GLvoid Screen::update(const GLint width, const GLint height, const glm::vec3 &color) {
    if (!initialized)
        initialized = true;
    Screen::width = static_cast<GLfloat>(width);
    Screen::height = static_cast<GLfloat>(height);
    setBackgroundColor(color);
}

GLvoid Screen::setBackgroundColor(const glm::vec3 &color) {
    backgroundColor = glm::vec4(color, 1.0f);
}

GLvoid Screen::clear() {
    glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

GLfloat Screen::getWidth() {
    if (!initialized)
        Error::massage("SCREEN", "UNITIALIZED");
    return width;
}

GLfloat Screen::getHeight() {
    if (!initialized)
        Error::massage("SCREEN", "UNITIALIZED");
    return height;
}

GLfloat Screen::getAspectRatio() {
    if (!initialized)
        Error::massage("SCREEN", "UNITIALIZED");
    return width / height;
}