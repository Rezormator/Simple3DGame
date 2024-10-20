#include "Scene.h"
#include <iostream>

Camera *Scene::camera;
Shader *Scene::shader;
std::map<std::string, Texture2D *> Scene::textures;
std::map<std::string, Rectangle *> Scene::rectangles;
std::map<std::string, Cube *> Scene::cubes;

GLvoid Scene::create() {
    camera = new Camera();
    camera->setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
    shader = new Shader("../Game/Shader/Shaders/shader.vert", "../Game/Shader/Shaders/shader.frag");
    textures["floor"] = new Texture2D("../Game/Texture2D/Textures/floor.png");
    textures["container"] = new Texture2D("../Game/Texture2D/Textures/container.png");
    rectangles["floor"] = new Rectangle(10, 10, textures["floor"], shader);
    rectangles["floor"]->setPosition(glm::vec3(0.0f, -3.5f, 0.0f));
    rectangles["floor"]->setRotation(glm::vec3(90.0f, 0.0f, 0.0f));
    cubes["container"] = new Cube(1, textures["container"], shader);
    cubes["container"]->setPosition(glm::vec3(0.0f, -3.0f, 0.0f));
}

GLvoid Scene::draw() {
    camera->update();
    shader->setMat4("view", camera->getViewMat());
    shader->setMat4("projection", camera->getProjectionMat());
    rectangles["floor"]->draw();
    cubes["container"]->draw();
}

GLvoid Scene::despose() {
    delete camera;
    delete shader;
    for (auto &texture : textures)
        delete texture.second;
    for (auto &rectangle : rectangles)
        delete rectangle.second;
    for (auto &cube : cubes)
        delete cube.second;
}
