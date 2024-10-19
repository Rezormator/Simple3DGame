#include "Cube.h"

Cube::Cube(GLfloat size, Texture2D *texture2D, Shader *shader)
: size(size), texture2D(texture2D), shader(shader) {
    createCube();
}

Cube::~Cube() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Cube::createCube() {
    const float vertices[] = {
        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 0.0f,
        size /  2.0f, size / -2.0f, size / -2.0f, 1.0f, 0.0f,
        size /  2.0f, size /  2.0f, size / -2.0f, 1.0f, 1.0f,
        size /  2.0f, size /  2.0f, size / -2.0f, 1.0f, 1.0f,

        size / -2.0f, size /  2.0f, size / -2.0f, 0.0f, 1.0f,
        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 0.0f,
        size / -2.0f, size / -2.0f, size /  2.0f, 0.0f, 0.0f,
        size /  2.0f, size / -2.0f, size /  2.0f, 1.0f, 0.0f,

        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 1.0f,
        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 1.0f,
        size / -2.0f, size /  2.0f, size /  2.0f, 0.0f, 1.0f,
        size / -2.0f, size / -2.0f, size /  2.0f, 0.0f, 0.0f,

        size / -2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,
        size / -2.0f, size /  2.0f, size / -2.0f, 1.0f, 1.0f,
        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,
        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,

        size / -2.0f, size / -2.0f, size /  2.0f, 0.0f, 0.0f,
        size / -2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,
        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,
        size /  2.0f, size /  2.0f, size / -2.0f, 1.0f, 1.0f,

        size /  2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,
        size /  2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,
        size /  2.0f, size / -2.0f, size /  2.0f, 0.0f, 0.0f,
        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,

        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,
        size /  2.0f, size / -2.0f, size / -2.0f, 1.0f, 1.0f,
        size /  2.0f, size / -2.0f, size /  2.0f, 1.0f, 0.0f,
        size /  2.0f, size / -2.0f, size /  2.0f, 1.0f, 0.0f,

        size / -2.0f, size / -2.0f, size /  2.0f, 0.0f, 0.0f,
        size / -2.0f, size / -2.0f, size / -2.0f, 0.0f, 1.0f,
        size / -2.0f, size /  2.0f, size / -2.0f, 0.0f, 1.0f,
        size /  2.0f, size /  2.0f, size / -2.0f, 1.0f, 1.0f,

        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,
        size /  2.0f, size /  2.0f, size /  2.0f, 1.0f, 0.0f,
        size / -2.0f, size /  2.0f, size /  2.0f, 0.0f, 0.0f,
        size / -2.0f, size /  2.0f, size / -2.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

GLvoid Cube::draw() const {
    glActiveTexture(GL_TEXTURE0);
    texture2D->bind();
    shader->use();
    shader->setInt("ourTexture", 0);
    shader->setMat4("model", model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}