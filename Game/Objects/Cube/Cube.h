#pragma once

#include "../../GameObject/GameObject.h"
#include "../../Texture2D/Texture2D.h"
#include "../../Shader/Shader.h"

class Cube : public GameObject {
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    GLfloat size;
    Texture2D *texture2D;
    Shader *shader;
    GLvoid createCube();
public:
    Cube(GLfloat size, Texture2D *texture2D, Shader *shader);
    ~Cube();
    GLvoid draw() const;
};
