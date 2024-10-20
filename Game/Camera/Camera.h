#pragma once

#include "../GameObject/GameObject.h"
#include "../../utils/utils.h"

constexpr auto WORLD_UP = glm::vec3(0.0f, 1.0f, 0.0f);
constexpr GLfloat DEFAULT_FOV = 45.0f;
constexpr GLfloat DEFAULT_NEAR_CLIP = 0.1f;
constexpr GLfloat DEFAULT_FAR_CLIP = 100.0f;
constexpr GLfloat MOVMENT_SPEAD = 0.02f;
constexpr GLfloat SENSITIVITY = 0.001f;

class Camera : public GameObject {
private:
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    GLfloat fov;
    glm::mat4 view;
    glm::mat4 projection;
    GLvoid updateTransform() override;
    GLvoid processInput();
    GLvoid processMouseInput();
public:
    explicit Camera(GLfloat fov = DEFAULT_FOV, const glm::vec3 &position = DEFAULT_POSITION,
                    const glm::vec3 &rotation = DEFAULT_ROTATION);
    virtual ~Camera() = default;
    GLvoid setFov(GLfloat fov);
    NODISCARD glm::mat4 getViewMat() const;
    NODISCARD glm::mat4 getProjectionMat() const;
};
