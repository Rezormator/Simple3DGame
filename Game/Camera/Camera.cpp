#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"
#include "../Input/Input.h"
#include "../Screen/Screen.h"

Camera::Camera(const GLfloat fov, const glm::vec3 &position, const glm::vec3 &rotation)
    : GameObject(position, rotation), front(0.0f, 0.0f, -1.0f), up(WORLD_UP), worldUp(WORLD_UP), view(1.0f),
      projection(1.0f) {
    setFov(fov);
}

GLvoid Camera::updateTransform() {
    processInput();
    processMouseInput();
    GameObject::updateTransform();
    front.x = glm::sin(rotation.y) * glm::cos(rotation.x);
    front.y = glm::sin(rotation.x);
    front.z = glm::cos(rotation.y) * glm::cos(rotation.x);
    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
    view = glm::lookAt(position, position + front, up);
    projection = glm::perspective(fov, Screen::getAspectRatio(), DEFAULT_NEAR_CLIP, DEFAULT_FAR_CLIP);
}

GLvoid Camera::processInput() {
    GLfloat movmentSpeed = MOVMENT_SPEAD;
    if (Input::getKeyPress(GLFW_KEY_LEFT_CONTROL))
        movmentSpeed += 0.2f;
    if (Input::getKeyPress(GLFW_KEY_W))
        position += front * movmentSpeed;
    if (Input::getKeyPress(GLFW_KEY_S))
        position -= front * movmentSpeed;
    if (Input::getKeyPress(GLFW_KEY_A))
        position -= right * movmentSpeed;
    if (Input::getKeyPress(GLFW_KEY_D))
        position += right * movmentSpeed;
    if (Input::getKeyPress(GLFW_KEY_SPACE))
        position = glm::vec3(position.x, position.y + MOVMENT_SPEAD, position.z);
    if (Input::getKeyPress(GLFW_KEY_LEFT_SHIFT))
        position = glm::vec3(position.x, position.y - MOVMENT_SPEAD, position.z);
    // position = glm::vec3(position.x, 0.0f, position.z);
}

GLvoid Camera::processMouseInput() {
    rotation.x = Input::getYOffset() * SENSITIVITY;
    rotation.y = Input::getXOffset() * -SENSITIVITY;
}


GLvoid Camera::setFov(const GLfloat fov) {
    this->fov = glm::radians(fov);
}

glm::mat4 Camera::getViewMat() const {
    return view;
}

glm::mat4 Camera::getProjectionMat() const {
    return projection;
}
