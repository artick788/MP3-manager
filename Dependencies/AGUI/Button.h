//
// Created by arthu on 10/11/2020.
//

#ifndef TURBOHIKER_BUTTON_H
#define TURBOHIKER_BUTTON_H

#include "gui_lib.h"
#include "Window.h"
#include "gui_utils.h"


namespace a_gui{
    class Button{
    private:
        sf::RectangleShape m_Button;
        sf::Text m_Description;
        sf::Font m_Font;
        float m_Width;
        float m_Height;
        float m_PosX;
        float m_PosY;
        float m_ButtonOutline;

        bool determineInBounds(int x, int y);

    public:
        Button(float posX, float posY, float width, float height, a_gui::Color buttonColor);

        void addText(const std::string text, unsigned int charSize, a_gui::Color textColor, const std::string& fontPath);

        void draw(a_gui::Window* window);

        bool mouseIntersects(a_gui::Window* window);

        void setBorder(float thickness, a_gui::Color color);

        void setPressed(float offset);

        void setReleased();


    };
}

#endif //TURBOHIKER_BUTTON_H
