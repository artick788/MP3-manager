//
// Created by arthu on 10/10/2020.
//

#include "AndromedaUtils.h"

void Andromeda::andromedaInit() {
    if (!glfwInit()){
        throw std::runtime_error("ANDROMEDA::ANDROMEDA_UTILS::ANDROMEDA_INIT::FAILED_TO_INITIALIZE_GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Andromeda::andromedaTerminate() {
    glfwTerminate();
}

void Andromeda::andromedaPollEvents() {
    glfwPollEvents();
}
