#include "Texture2D.h"
#include <iostream>
#include <stb/stb_image.h>

Texture2D::Texture2D(const char *texturePath, const GLint wrap, const GLint filtration) {
    createTexture(wrap, filtration);
    loadTexture(texturePath);
}

GLvoid Texture2D::createTexture(const GLint wrap, const GLint filtration) {
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtration);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtration);
}

GLvoid Texture2D::loadTexture(const char *texturePath) {
    GLint numChannels;
    const unsigned char *data = stbi_load(texturePath, &width, &height, &numChannels, 0);
    if (!data){
        std::cout << "LOADING_TEXTURE_FAILED" << std::endl;
        return;
    }

    const auto format = numChannels == 1 ? GL_RED : numChannels == 3 ? GL_RGB : GL_RGBA;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

GLvoid Texture2D::bind() const {
    glBindTexture(GL_TEXTURE_2D, textureID);
}

GLvoid Texture2D::dispose() {
    glDeleteTextures(1, &textureID);
}
