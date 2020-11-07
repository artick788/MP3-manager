//
// Created by arthu on 05/10/2020.
//

#include "Window.h"
#include "EngineCore/stb_image.h"

void Andromeda::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {

}

void Andromeda::frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Andromeda::Window::Window(unsigned int width, unsigned int height, const char *title): m_Width(width), m_Height(height) {
    m_Context = glfwCreateWindow(m_Width, m_Height, title, NULL, NULL);
    if (!m_Context){
        throw std::runtime_error("Window creation failed");
    }
    glfwMakeContextCurrent(m_Context);
    glfwSetFramebufferSizeCallback(m_Context, frameBufferSizeCallback);
    glfwSetKeyCallback(m_Context, keyCallback);
}

void Andromeda::Window::swapBuffers() {
    glfwSwapBuffers(m_Context);
}

void Andromeda::Window::setColor(float red, float green, float blue) {
    glClearColor(red, green, blue, 1.0f);
}

void Andromeda::Window::setViewPort(int x, int y) {
    glViewport(x, y, m_Width, m_Height);
}

void Andromeda::Window::close() {
    glfwSetWindowShouldClose(m_Context, GLFW_TRUE);
}

bool Andromeda::Window::windowShouldClose() {
    return glfwWindowShouldClose(m_Context);
}

void Andromeda::Window::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Andromeda::Window::enableVerticalSync(bool choice) {
    glfwSwapInterval(choice);
}

unsigned int Andromeda::Window::getWidth() const {
    return m_Width;
}

unsigned int Andromeda::Window::getHeight() const {
    return m_Height;
}

void Andromeda::Window::setMouseInputMode(int input) {
    glfwSetInputMode(m_Context, GLFW_CURSOR, input);
}

void Andromeda::Window::getMousePosition(double &xPos, double &yPos) {
    glfwGetCursorPos(m_Context, &xPos, &yPos);
}

int Andromeda::Window::getKey(int key) const {
    return glfwGetKey(m_Context, key);
}

void Andromeda::Window::setWindowIcon(const std::string &tile) {
    GLFWimage icon[1];
    stbi_set_flip_vertically_on_load(true);
    icon[0].pixels = stbi_load(tile.c_str(), &icon[0].width, &icon[0].height, nullptr, 4);
    stbi_image_free(icon[0].pixels);
    glfwSetWindowIcon(m_Context, 1, icon);
}

glm::mat4 Andromeda::Window::getPerspectiveMatrix(float fov, float zNear, float zFar) {
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(fov), static_cast<float >(m_Width) / static_cast<float >(m_Height), zNear, zFar);
    return projection;
}

glm::mat4 Andromeda::Window::getOrthogonalMatrix() {
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::ortho(0.0f, static_cast<float>(m_Width), 0.0f, static_cast<float>(m_Height));
    return projection;
}

int Andromeda::Window::getMouseInput(int mouseButton) {
    return glfwGetMouseButton(m_Context, mouseButton);
}

void Andromeda::Window::setScrollCallback(GLFWscrollfun callback) {
    glfwSetScrollCallback(m_Context, callback);
}

void Andromeda::Window::setMousePosCallback(GLFWcursorposfun callback) {
    glfwSetCursorPosCallback(m_Context, callback);
}
