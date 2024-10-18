#include "Camera.h"
#include <glm/glm/gtc/matrix_transform.hpp>
#include "../Screen/Screen.h"

Camera::Camera(const glm::vec3 &up, GLfloat fov, GLfloat nearClip, GLfloat farClip, const glm::vec3 &position,
               const glm::vec3 &rotation) : worldUp(up), nearClip(nearClip), farClip(farClip),
                                            GameObject(position, rotation) {
    setFov(fov);
}


GLvoid Camera::setFov(const GLfloat fov) {
    this->fov = glm::radians(fov);
}

glm::mat4 Camera::getViewMatrix() const {
    return view;
}

glm::mat4 Camera::getProjectionMatrix() const {
    return projection;
}

GLvoid Camera::updateCameraVectors() {
    updateModel();
    front.x = glm::sin(rotation.y) * glm::cos(rotation.x);
    front.y = glm::sin(rotation.x);
    front.z = glm::cos(rotation.y) * glm::cos(rotation.x);
    front = glm::normalize(front);
    view = glm::lookAt(position, front, worldUp);
    projection = glm::perspective(fov, Screen::getAspectRatio(), nearClip, farClip);
}
