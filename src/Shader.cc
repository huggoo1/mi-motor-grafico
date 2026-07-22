#define GL_GLEXT_PROTOTYPES
#include "Shader.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

Shader::Shader(const char* vp, const char* fp) {
    std::string textVertex = readShader(vp);
    std::string textFrag = readShader(fp);

    const char* startVertex = textVertex.c_str();
    const char* startFrag = textFrag.c_str();

    // 1. CREAR Y COMPILAR VERTEX SHADER
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &startVertex, NULL);
    glCompileShader(vs);
    checkCompileErrors(vs, "VERTEX");

    // 2. CREAR Y COMPILAR FRAGMENT SHADER
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &startFrag, NULL);
    glCompileShader(fs);
    checkCompileErrors(fs, "FRAGMENT");

    // 3. VINCULAR PROGRAMA
    _program = glCreateProgram();
    glAttachShader(_program, vs);
    glAttachShader(_program, fs);
    glLinkProgram(_program);
    checkCompileErrors(_program, "PROGRAM");

    // 4. LIMPIEZA
    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader() {
    glDeleteProgram(_program);
}

std::string Shader::readShader(const char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << path << '\n';
        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();

    return ss.str();
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" 
                      << infoLog << "\n---------------------------------------------------" << std::endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" 
                      << infoLog << "\n---------------------------------------------------" << std::endl;
        }
    }
}

void Shader::bind() const {
    glUseProgram(_program);
}

void Shader::release() const {
    glUseProgram(0);
}

void Shader::setBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(_program, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(_program, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(_program, name.c_str()), value);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
    glUniform3fv(glGetUniformLocation(_program, name.c_str()), 1, &value[0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
    glUniformMatrix4fv(glGetUniformLocation(_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}