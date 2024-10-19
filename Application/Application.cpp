#include "Application.h"
#include "../Error/Error.h"

Game *Application::game;

GLvoid Application::initielizeGLFW() {
    if (!glfwInit())
        Error::massage("GLFW", "FAILD_TO_INITIELIZE");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLvoid Application::crate() {
    initielizeGLFW();
    game = new Game("Simple3DGame", false);
}

GLvoid Application::run() {
    game->run();
}

GLvoid Application::shut() {
    game->shut();
    delete game;
    glfwTerminate();
}
