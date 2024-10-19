#include "Game.h"
#include "../Error/Error.h"
#include "Shader/Shader.h"
#include "Texture2D/Texture2D.h"
#include "Objects/Rectangle/Rectangle.h"
#include "Objects/Cube/Cube.h"
#include "Camera/Camera.h"
#include "Input/Input.h"

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
}

GLFWwindow *Game::getWindow() const {
    return window;
}

GLvoid Game::run() const {
    const auto camera = new Camera();
    const auto shader = new Shader("../Game/Shader/Shaders/shader.vert", "../Game/Shader/Shaders/shader.frag");
    const auto texture = new Texture2D("../Game/Texture2D/Textures/tile.png", GL_REPEAT);
    const auto rectangle = new Rectangle(1.0f, 1.0f, texture, shader);
    const auto cube = new Cube(1.0f, texture, shader);

    rectangle->setPosition(glm::vec3(0.0f, -1.0f, 0.0f));
    rectangle->setRotation(glm::vec3(90.0f, 0.0f, 0.0f));
    cube->setPosition(glm::vec3(3.0f, -0.5f, -1.0f));

    // const auto view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    // const auto projection = glm::perspective(glm::radians(45.0f), 1.777777f, 0.1f, 100.0f);

    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera->update();
        shader->setMat4("view", camera->getViewMat());
        shader->setMat4("projection", camera->getProjectionMat());
        cube->draw();
        for (GLfloat i = -15.0f; i <= 15.0f; i += 1.0f) {
            for (GLfloat j = -15.0f; j <= 15.0f; j += 1.0f) {
                rectangle->setPosition(glm::vec3(i, -1.0f, j));
                rectangle->draw();
            }
        }

        for (GLfloat i = -15.0f; i <= 15.0f; i += 1.0f) {
            for (GLfloat j = -0.5f; j <= 5.5f; j += 1.0f) {
                cube->setPosition(glm::vec3(i, j, 3.0f));
                cube->draw();
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (Input::getKeyPress(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);
    }

    delete shader;
    delete texture;
    delete rectangle;
    delete cube;
    delete camera;
}

GLvoid Game::shut() const {
    glfwDestroyWindow(window);
}
