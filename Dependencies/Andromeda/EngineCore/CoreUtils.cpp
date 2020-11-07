//
// Created by arthu on 05/10/2020.
//

#include "CoreUtils.h"

void andromedaCore::AdromedaCoreInit() {
    if (glewInit() != GLEW_OK) {
        throw std::runtime_error("NEBULA::UTILS::NEBULA_CONTEXT_INIT::FAILED_TO_INITIALIZE_GLEW");
    }
    glEnable(GL_DEBUG_OUTPUT);
}

int andromedaCore::getMaxVertexAttribs() {
    int nrVertexShaderAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrVertexShaderAttributes);
    return nrVertexShaderAttributes;
}

int andromedaCore::getMaxUBOsize() {
    int maxUBOsize;
    glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &maxUBOsize);
    return maxUBOsize;
}

std::string andromedaCore::getOpenGLversion() {
    const unsigned char* version = glGetString(GL_VERSION);
    char* temp = (char*) version;
    std::string retVal = temp;
    return retVal;
}

void andromedaCore::checkOGLError() {
    GLenum error;
    while((error = glGetError()) != GL_NO_ERROR){
        std::string err = "OpenGL has ended with exit code " + std::to_string(error);
        throw std::runtime_error(err);
    }
    //std::cout << "no error" << std::endl;
}

bool andromedaCore::GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()){
        std::string e = "[OpenGL Error] (" + std::to_string(error) + "): " + function + " in file " + file + " at line " + std::to_string(line);
        throw std::runtime_error(e);
    }
    return true;
}

void andromedaCore::clearOGLerror() {
    while (glGetError() != GL_NO_ERROR){
    }
}

void andromedaCore::errorCallback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}