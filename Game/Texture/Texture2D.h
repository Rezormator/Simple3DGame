#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../../Dispose/IDisposable.h"

class Texture2D : public IDisposable {
private:
    static constexpr GLint DEFAULT_WRAP = GL_REPEAT;
    static constexpr GLint DEFAULT_FILTRATION = GL_LINEAR;
    GLuint textureID;
    GLint width;
    GLint height;
    GLvoid createTexture(GLint wrap, GLint filtration);
    GLvoid loadTexture(const char *texturePath);
public:
    explicit Texture2D(const char *texturePath, GLint wrap = DEFAULT_WRAP, GLint filtration = DEFAULT_FILTRATION);
    GLvoid bind() const;
    GLvoid dispose() override;
};
