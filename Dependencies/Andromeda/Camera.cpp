//
// Created by arthu on 11/10/2020.
//

#include "Camera.h"

Andromeda::Camera::Camera() {
    m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    m_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    m_CameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Andromeda::Camera::moveForward(float cameraSpeed) {
    m_CameraPos += cameraSpeed * m_CameraFront;
}

void Andromeda::Camera::moveBack(float cameraSpeed) {
    m_CameraPos -= cameraSpeed * m_CameraFront;
}

void Andromeda::Camera::moveLeft(float cameraSpeed) {
    m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
}

void Andromeda::Camera::moveRight(float cameraSpeed) {
    m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * cameraSpeed;
}

void Andromeda::Camera::moveUp(float cameraSpeed) {
    m_CameraPos += cameraSpeed * m_CameraUp;
}

void Andromeda::Camera::moveDown(float cameraSpeed) {
    m_CameraPos -= cameraSpeed * m_CameraUp;
}

glm::mat4 Andromeda::Camera::getViewMatrix() {
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);
    return view;
}

void Andromeda::Camera::setCameraPos(glm::vec3 &newPos) {
    m_CameraFront = newPos;
}
