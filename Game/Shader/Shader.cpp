#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm/gtc/type_ptr.hpp>

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    const std::string vertexCode = loadCode(vertexPath);
    const std::string fragmentCode = loadCode(fragmentPath);
    const char *vertexShaderCode = vertexCode.c_str();
    const char *fragmentShaderCode = fragmentCode.c_str();
    const GLuint vertexShader = compileShader(vertexShaderCode, GL_VERTEX_SHADER);
    const GLuint fragmentShader = compileShader(fragmentShaderCode, GL_FRAGMENT_SHADER);
    createProgram(vertexShader, fragmentShader);
}

std::string Shader::loadCode(const char *path) {
    std::ifstream codeStream;
    std::stringstream shaderCode;
    codeStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        codeStream.open(path);
        shaderCode << codeStream.rdbuf();
        codeStream.close();
    }
    catch (std::ifstream::failure &e) {
        std::cout << "LOADING_SHADER_FAILED: " << e.what() << std::endl;
    }
    return shaderCode.str();
}

GLuint Shader::compileShader(const char *code, const GLuint shaderType) {
    const GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);
    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if(!compiled) {
        char infoLog[BUFSIZ];
        glGetShaderInfoLog(shader, BUFSIZ, nullptr, infoLog);
        std::cout << "SHADER" << infoLog << std::endl;
    }
    return shader;
}

GLvoid Shader::createProgram(const GLuint vertexShader, const GLuint fragmentShader) {
    shaderID = glCreateProgram();
    glAttachShader(shaderID, vertexShader);
    glAttachShader(shaderID, fragmentShader);
    glLinkProgram(shaderID);
    GLint linked;
    glGetProgramiv(shaderID, GL_LINK_STATUS, &linked);
    if(!linked) {
        char infoLog[BUFSIZ];
        glGetProgramInfoLog(shaderID, BUFSIZ, nullptr, infoLog);
        std::cout << "SHADER_PROGRAM" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLvoid Shader::use() const {
    glUseProgram(shaderID);
}

GLvoid Shader::setFloat(const char *name, const GLfloat value) const {
    glUniform1f(glGetUniformLocation(shaderID, name), value);
}

GLvoid Shader::setInt(const char *name, const GLint value) const {
    glUniform1i(glGetUniformLocation(shaderID, name), value);
}

GLvoid Shader::setMat4(const char *name, const glm::mat4 &value) const {
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, glm::value_ptr(value));
}

GLvoid Shader::setVec3(const char *name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(shaderID, name), 1, glm::value_ptr(value));
}

GLvoid Shader::dispose() {
    glDeleteProgram(shaderID);
}
