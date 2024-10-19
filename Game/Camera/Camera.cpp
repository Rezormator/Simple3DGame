#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(const GLfloat fov, const glm::vec3 &position, const glm::vec3 &rotation)
    : GameObject(position, rotation), front(0.0f, 0.0f, -1.0f), up(WORLD_UP), worldUp(WORLD_UP), view(1.0f), projection(1.0f) {
    setFov(fov);
    updateTransform();
}

GLvoid Camera::updateTransform() {
    GameObject::updateTransform();
    front.x = glm::sin(rotation.y) * glm::cos(rotation.x);
    front.y = glm::sin(rotation.x);
    front.z = glm::cos(rotation.y) * glm::cos(rotation.x);
    front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
    view = glm::lookAt(position, position + front, up);
    projection = glm::perspective(fov, ASPECT_RATIO, DEFAULT_NEAR_CLIP, DEFAULT_FAR_CLIP);
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
