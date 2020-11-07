//
// Created by arthu on 05/10/2020.
//

#ifndef ADROMEDA_WINDOW_H
#define ADROMEDA_WINDOW_H

#include "AndromedaLib.h"
#include "AndromedaUtils.h"

namespace Andromeda{
    static
    void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    class Window{
    private:
        GLFWwindow* m_Context;
        unsigned int m_Width;
        unsigned int m_Height;

    public:
        Window(unsigned int width, unsigned int height, const char* title);

        void swapBuffers();

        void setColor(float red, float green, float blue);

        void enableVerticalSync(bool choice);

        void setViewPort(int x, int y);

        void setMouseInputMode(int input);

        void getMousePosition(double &xPos, double &yPos);

        int getMouseInput(int mouseButton);

        void setWindowIcon(const std::string& tile);

        void close();

        void clear();

        bool windowShouldClose();

        unsigned int getWidth() const;

        unsigned int getHeight() const;

        int getKey(int key) const;

        glm::mat4 getPerspectiveMatrix(float fov, float zNear, float zFar);

        glm::mat4 getOrthogonalMatrix();

        void setScrollCallback(GLFWscrollfun callback);

        void setMousePosCallback(GLFWcursorposfun callback);

    };
}


#endif //ADROMEDA_WINDOW_H
