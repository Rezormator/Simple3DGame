#pragma once

#include "../../GameObject/GameObject.h"
#include "../../Texture2D/Texture2D.h"
#include "../../Shader/Shader.h"

class Rectangle : public GameObject {
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    GLfloat width;
    GLfloat height;
    Texture2D *texture2D;
    Shader *shader;
    GLvoid createRectangle();
public:
    Rectangle(GLfloat width, GLfloat height, Texture2D *texture2D, Shader *shader);
    ~Rectangle();
    GLvoid draw() const;
};
