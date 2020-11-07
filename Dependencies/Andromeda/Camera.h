#ifndef ANDROMEDA_CAMERA_H
#define ANDROMEDA_CAMERA_H

#include "AndromedaLib.h"
#include "Window.h"

namespace Andromeda{
    class Camera{
    private:
        glm::vec3 m_CameraPos;
        glm::vec3 m_CameraUp;
        glm::vec3 m_CameraFront;

    public:
        explicit Camera();

        void moveForward(float cameraSpeed);

        void moveBack(float cameraSpeed);

        void moveLeft(float cameraSpeed);

        void moveRight(float cameraSpeed);

        void moveUp(float cameraSpeed);

        void moveDown(float cameraSpeed);

        void setCameraPos(glm::vec3 &newPos);

        glm::mat4 getViewMatrix();
    };
}

#endif //ANDROMEDA_CAMERA_H
