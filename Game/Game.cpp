#include "Game.h"
#include "../Error/Error.h"
#include "Shader/Shader.h"
#include "Input/Input.h"
#include "Scene/Scene.h"
#include "Screen/Screen.h"
#include "Time/Time.h"

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
    Input::setWindow(window);
    Screen::update(width, height, DEFAULT_COLOR);
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
    glfwSetCursorPosCallback(window, Input::mouseCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

GLFWwindow *Game::getWindow() const {
    return window;
}

GLvoid Game::run() const {
    Scene::create();

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {
        Screen::clear();
        Time::calculateDeltaTime();

        Scene::draw();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (Input::getKeyPress(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);
    }

    Scene::despose();
}

GLvoid Game::shut() const {
    glfwDestroyWindow(window);
}
