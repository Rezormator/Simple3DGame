#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm/glm.hpp>
#include <string>
#include "../../Dispose/IDisposable.h"

class Shader : public IDisposable{
private:
    GLuint shaderID;
    static std::string loadCode(const char *path);
    static GLuint compileShader(const char *code, GLenum shaderType);
    GLvoid createProgram(GLuint vertexShader, GLuint fragmentShader);
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    GLvoid use() const;
    GLvoid setFloat(const char *name, GLfloat value) const;
    GLvoid setInt(const char *name, GLint value) const;
    GLvoid setMat4(const char *name, const glm::mat4 &value) const;
    GLvoid setVec3(const char *name, const glm::vec3 &value) const;
    GLvoid dispose() override;
};
