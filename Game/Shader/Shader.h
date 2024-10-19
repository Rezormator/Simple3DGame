#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

class Shader {
private:
    GLuint ID;
    static std::string loadCode(const char *path);
    static GLuint compileShader(const char *code, GLuint shaderType);
    GLvoid createProgram(GLuint vertShader, GLuint fragShader);
public:
    Shader(const char *vertPath, const char *fragPath);
    GLvoid use() const;
    GLvoid setFloat(const char *name, GLfloat value) const;
    GLvoid setInt(const char *name, GLint value) const;
    GLvoid setVec3(const char *name, const glm::vec3 &value) const;
    GLvoid setMat4(const char *name, const glm::mat4 &value) const;
    GLvoid deleteShader() const;
};
