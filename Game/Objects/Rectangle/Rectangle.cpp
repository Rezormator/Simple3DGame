#include "Rectangle.h"

Rectangle::Rectangle(GLfloat width, GLfloat height, Texture2D *texture2D, Shader *shader)
    : width(width), height(height), texture2D(texture2D), shader(shader){
    createRectangle();
}

Rectangle::~Rectangle() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

GLvoid Rectangle::createRectangle() {
    const float vertices[] = {
        width / -2, height / -2, 0.0f, 0.0f, 0.0f,
        width / -2, height / 2,  0.0f, 0.0f, 1.0f,
        width / 2,  height / 2,  0.0f, 1.0f, 1.0f,
        width / 2,  height / -2, 0.0f, 1.0f, 0.0f,
    };

    const unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

GLvoid Rectangle::draw() const {
    glActiveTexture(GL_TEXTURE_2D);
    texture2D->bind();
    shader->setMat4("model", this->getModel());
    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
