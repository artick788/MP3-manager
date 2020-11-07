//
// Created by arthu on 05/10/2020.
//

#include "Shader.h"

andromedaCore::Shader::Shader(const std::string &vertexShaderFile, const std::string &fragmentShaderFile) {
    std::string vfs = readFromFile(vertexShaderFile);
    std::string ffs = readFromFile(fragmentShaderFile);
    unsigned int vertexShader = buildAndCompileShader(vfs.c_str(), ShaderType::VERTEX);
    unsigned int fragmentShader = buildAndCompileShader(ffs.c_str(), ShaderType::FRAGMENT);
    link(vertexShader, fragmentShader);
}

std::string andromedaCore::Shader::readFromFile(const std::string &fileName) {
    std::string retVal;
    std::string line;
    std::ifstream file(fileName);
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        else{
            retVal += line + "\n";
        }
    }
    return retVal;
}

andromedaCore::Shader::~Shader() {
    glDeleteProgram(m_ShaderProgram);
}

andromedaCore::Shader::Shader(const char* &vertexShaderSource, const char* &fragmentShaderSource) {
    unsigned int vertexShader = buildAndCompileShader(vertexShaderSource, ShaderType::VERTEX);
    unsigned int fragmentShader = buildAndCompileShader(fragmentShaderSource, ShaderType::FRAGMENT);
    link(vertexShader, fragmentShader);
}

unsigned int andromedaCore::Shader::buildAndCompileShader(const char* shaderSource, andromedaCore::Shader::ShaderType type) {
    unsigned int retVal;
    if (type == ShaderType::VERTEX){
        retVal = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (type == ShaderType::FRAGMENT){
        retVal = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else if (type == ShaderType::GEOMETRY){
        retVal = glCreateShader(GL_GEOMETRY_SHADER);
    }
    else{
        throw std::runtime_error("ANDROMEDACORE::SHADER::BUILD_AND_COMPILE_SHADER::INVALID_SHADER_TYPE");
    }
    int success;
    char infolog[512];
    glShaderSource(retVal, 1, &shaderSource, NULL);
    glCompileShader(retVal);
    glGetShaderiv(retVal, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(retVal, 512, NULL, infolog);
        std::string oglError(infolog);
        std::string error = "ANDROMEDACORE::SHADER::BUILD_AND_COMPILE::COMPILING_FAILED\n" + oglError + "\n";
        throw std::runtime_error(error);
    }
    return retVal;
}

void andromedaCore::Shader::link(unsigned int &vertexShader, unsigned int &fragmentShader) {
    m_ShaderProgram = glCreateProgram();
    glAttachShader(m_ShaderProgram, vertexShader);
    glAttachShader(m_ShaderProgram, fragmentShader);
    glLinkProgram(m_ShaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
        std::string oglError(infoLog);
        std::string error = "ANDROMEDACORE::SHADER::LINK::LINKING_FAILED\n" + oglError + "\n";
        throw std::runtime_error(error);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void andromedaCore::Shader::bind() {
    glUseProgram(m_ShaderProgram);
}

void andromedaCore::Shader::unbind() {
    glUseProgram(0);
}

unsigned int andromedaCore::Shader::getUniformLocation(const std::string &name) {
    int location = glGetUniformLocation(m_ShaderProgram, name.c_str());
    if (location == -1){
        throw std::runtime_error("ANDROMEDACORE::SHADER::GET_UNIFORM_LOCATION::CANNOT_FIND_LOCATION");
    }
    return location;
}

void andromedaCore::Shader::setUniform1ui(const std::string &name, unsigned int ui1) {
    glUniform1ui(getUniformLocation(name), ui1);
}

void andromedaCore::Shader::setUniform2ui(const std::string &name, unsigned int ui1, unsigned int ui2) {
    glUniform2ui(getUniformLocation(name), ui1, ui2);
}

void andromedaCore::Shader::setUniform3ui(const std::string &name, unsigned int ui1, unsigned int ui2, unsigned int ui3) {
    glUniform3ui(getUniformLocation(name), ui1, ui2, ui3);
}

void andromedaCore::Shader::setUniform4ui(const std::string &name, unsigned int ui1, unsigned int ui2, unsigned int ui3,
                                          unsigned int ui4) {
    glUniform4ui(getUniformLocation(name), ui1, ui2, ui3, ui4);
}

void andromedaCore::Shader::setUniform1i(const std::string &name, unsigned int i1) {
    glUniform1i(getUniformLocation(name), i1);
}

void andromedaCore::Shader::setUniform2i(const std::string &name, unsigned int i1, unsigned int i2) {
    glUniform2i(getUniformLocation(name), i1, i2);
}

void andromedaCore::Shader::setUniform3i(const std::string &name, unsigned int i1, unsigned int i2, unsigned int i3) {
    glUniform3i(getUniformLocation(name), i1, i2, i3);
}

void andromedaCore::Shader::setUniform4i(const std::string &name, unsigned int i1, unsigned int i2, unsigned int i3,
                                         unsigned int i4) {
    glUniform4i(getUniformLocation(name), i1, i2, i3, i4);
}

void andromedaCore::Shader::setUniform1f(const std::string &name, float f1) {
    glUniform1f(getUniformLocation(name), f1);
}

void andromedaCore::Shader::setUniform2f(const std::string &name, float f1, float f2) {
    glUniform2f(getUniformLocation(name), f1, f2);
}

void andromedaCore::Shader::setUniform3f(const std::string &name, float f1, float f2, float f3) {
    glUniform3f(getUniformLocation(name), f1, f2, f3);
}

void andromedaCore::Shader::setUniform4f(const std::string &name, float f1, float f2, float f3, float f4) {
    glUniform4f(getUniformLocation(name), f1, f2, f3, f4);
}

void andromedaCore::Shader::setUniformMatrix2f(const std::string &name, const float *value) {
    glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, value);
}

void andromedaCore::Shader::setUniformMatrix3f(const std::string &name, const float *value) {
    glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, value);
}

void andromedaCore::Shader::setUniformMatrix4f(const std::string &name, const float *value) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, value);
}

void andromedaCore::Shader::setUniform1d(const std::string &name, double d1) {
    glUniform1d(getUniformLocation(name), d1);
}

void andromedaCore::Shader::setUniform2d(const std::string &name, double d1, double d2) {
    glUniform2d(getUniformLocation(name), d1, d2);
}

void andromedaCore::Shader::setUniform3d(const std::string &name, double d1, double d2, double d3) {
    glUniform3d(getUniformLocation(name), d1, d2, d3);
}

void andromedaCore::Shader::setUniform4d(const std::string &name, double d1, float d2, double d3, double d4) {
    glUniform4d(getUniformLocation(name), d1, d2, d3, d4);
}

void andromedaCore::Shader::setUniformMatrix2d(const std::string &name, const double *value) {
    glUniformMatrix2dv(getUniformLocation(name), 1, GL_FALSE, value);
}

void andromedaCore::Shader::setUniformMatrix3d(const std::string &name, const double *value) {
    glUniformMatrix3dv(getUniformLocation(name), 1, GL_FALSE, value);
}

void andromedaCore::Shader::setUniformMatrix4d(const std::string &name, const double *value) {
    glUniformMatrix4dv(getUniformLocation(name), 1, GL_FALSE, value);
}
