#pragma once

#include "../Utils/utils.h"
#include "GLFW/glfw3.h"
#include "glm/glm/glm.hpp"

class GameObject {
private:
    glm::mat4 model;
protected:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
public:
    static constexpr glm::vec3 X_AXIS{1.0f, 0.0f, 0.0f};
    static constexpr glm::vec3 Y_AXIS{0.0f, 1.0f, 0.0f};
    static constexpr glm::vec3 Z_AXIS{0.0f, 0.0f, 1.0f};
    static constexpr glm::vec3 DEFAULT_POS{0.0f};
    static constexpr glm::vec3 DEFAULT_ROT{0.0f};
    static constexpr glm::vec3 DEFAULT_SCALE{1.0f};
    explicit GameObject(const glm::vec3 &position = DEFAULT_POS, const glm::vec3 &rotation = DEFAULT_ROT,
               const glm::vec3 &scale = DEFAULT_SCALE);
    GLvoid setPostion(const glm::vec3 &position);
    GLvoid setRotation(const glm::vec3 &rotation);
    GLvoid setScale(const glm::vec3 &scale);
    NODISCARD glm::vec3 getPostion() const;
    NODISCARD glm::vec3 getRotation() const;
    NODISCARD glm::vec3 getScale() const;
    NODISCARD glm::mat4 getModel() const;
    GLvoid updateModel();
};
