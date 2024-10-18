#include "Application.h"

Game *Application::game = nullptr;

GLvoid Application::initGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLvoid Application::create(const char *title) {
    initGLFW();
    game = Game::getInstance(title);
    game->create();
}

GLvoid Application::run() {
    game->run();
}

GLvoid Application::terminate() {
    game->dispose();
    Game::deleteInstance();
    glfwTerminate();
}
