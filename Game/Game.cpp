#include "Game.h"
#include <iostream>
#include "Screen/Screen.h"
#include "Shader/Shader.h"
#include "Texture/Texture2D.h"
#include "Objects/Rectangle/Rectangle.h"
#include <glm/glm/gtc/matrix_transform.hpp>

Game *Game::instance = nullptr;

Game::Game(const char *title)
    : title(title) {
}

GLvoid Game::crateWindow() {
    const auto monitor = glfwGetPrimaryMonitor();
    const auto screen = glfwGetVideoMode(monitor);
    const auto width = screen->width;
    const auto height = screen->height;
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
        std::cout << "CREATE_WINDOW_ERROR" << std::endl;
    glfwMakeContextCurrent(window);
    Screen::setScreenSize(width, height);
    Screen::setBackgroundColor(DEFAULT_BACKROUND_COLOR);
}

GLvoid Game::loadGlad() {
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        std::cout << "LOAD_GLAD_ERROR" << std::endl;
}

GLvoid Game::setCallBacks() const {
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
}

GLvoid Game::frameBufferSizeCallback(GLFWwindow *window, const GLint width, const GLint height) {
    glViewport(0, 0, width, height);
}

GLFWwindow *Game::getWindow() const {
    return window;
}

GLvoid Game::create() {
    crateWindow();
    loadGlad();
    setCallBacks();
}

Game *Game::getInstance(const char *title) {
    if (instance == nullptr)
        instance = new Game(title);
    return instance;
}

GLvoid Game::deleteInstance() {
    if (instance == nullptr)
        return;
    delete instance;
    instance = nullptr;
}

GLvoid Game::run() const {
    const auto shader = new Shader("../Game/Shader/Shaders/Shader.vert", "../Game/Shader/Shaders/Shader.frag");
    const auto texture = new Texture2D("../Game/Texture/Textures/grass.png");
    const auto rectangle = new Rectangle(1, 1, texture, shader);
    glm::vec3 position(1.0f, 0.0f, 0.0f);
    rectangle->setPostion(position);
    // glm::vec3 rotation(90.0f, 0.0f, 0.0f);
    // rectangle->setRotation(rotation);

    // auto view = glm::mat4(1.0f);
    // view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    // shader->setMat4("view", view);
    // auto projection = glm::perspective(glm::radians(45.0f), 1.777777f, 0.1f, 100.0f);
    // shader->setMat4("projection", projection);

    while (!glfwWindowShouldClose(window)) {
        Screen::clear();
        rectangle->draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    delete shader;
    delete texture;
    delete rectangle;
}

GLvoid Game::dispose() const {
    glfwDestroyWindow(window);
}
