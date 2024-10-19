#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../../utils/utils.h"
#include "GameObjectDefaults.h"

class GameObject {
private:
    glm::mat4 model;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    GLvoid updateModel();
public:
    explicit GameObject(const glm::vec3 &position = DEFAULT_POSITION, const glm::vec3 &rotation = DEFAULT_ROTATION,
        const glm::vec3 &scale = DEFAULT_SCALE);
    GLvoid setPosition(const glm::vec3 &position);
    GLvoid setRotation(const glm::vec3 &rotation);
    GLvoid setScale (const glm::vec3 &scale);
    NODISCARD glm::mat4 getModel() const;
    NODISCARD glm::vec3 getPosition() const;
    NODISCARD glm::vec3 getRotation() const;
    NODISCARD glm::vec3 getScale() const;
    GLvoid update();
};
