#include "GameObject.h"
#include <glm/glm/gtc/matrix_transform.hpp>

GameObject::GameObject(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale)
    : position(position), rotation(rotation), scale(scale) {
}

GLvoid GameObject::setPostion(const glm::vec3 &position) {
    this->position = position;
    updateModel();
}

GLvoid GameObject::setRotation(const glm::vec3 &rotation) {
    this->rotation = rotation;
    updateModel();
}

GLvoid GameObject::setScale(const glm::vec3 &scale) {
    this->scale = scale;
    updateModel();
}

glm::vec3 GameObject::getPostion() const {
    return position;
}

glm::vec3 GameObject::getRotation() const {
    return rotation;
}

glm::vec3 GameObject::getScale() const {
    return scale;
}

glm::mat4 GameObject::getModel() const {
    return model;
}

GLvoid GameObject::updateModel() {
    model = glm::translate(glm::mat4(1.0f), position);
    model = glm::rotate(model, rotation.x, X_AXIS);
    model = glm::rotate(model, rotation.y, Y_AXIS);
    model = glm::rotate(model, rotation.z, Z_AXIS);
    model = glm::scale(model, scale);
}
