#pragma once

#include <glad/glad.h>
#include "../../GameObject.h"
#include "../../Texture/Texture2D.h"
#include "../../Shader/Shader.h"
#include "../../../Dispose/IDisposable.h"

class Rectangle : public GameObject {
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
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
