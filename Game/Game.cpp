#include "Game.h"
#include "../Error/Error.h"

Game::Game(const char *title, const GLboolean fullscreen) {
    createWindow(title, fullscreen);
    loadGLAD();
    setCallbacks();
}

GLvoid Game::createWindow(const char *title, const GLboolean fullscreen) {
    const auto monitor = glfwGetPrimaryMonitor();
    const auto mode = glfwGetVideoMode(monitor);
    const auto width = mode->width;
    const auto height = mode->height;
    window = glfwCreateWindow(width, height, title, fullscreen ? monitor : nullptr, nullptr);
    if (!window)
        Error::massage("WINDOW", "FAILD_TO_CREATE");
    glfwMakeContextCurrent(window);
}

GLvoid Game::loadGLAD() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        Error::massage("GLAD", "FAILD_TO_LOAD");
}

GLvoid Game::frameBufferSizeCallback(GLFWwindow *window, const GLint width, const GLint height) {
    glViewport(0, 0, width, height);
}

GLvoid Game::setCallbacks() const {
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

GLFWwindow *Game::getWindow() const {
    return window;
}

GLvoid Game::run() const {
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

GLvoid Game::shut() const {
    glfwDestroyWindow(window);
}
