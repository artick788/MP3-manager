//
// Created by arthu on 12/11/2020.
//

#ifndef TURBOHIKER_TEXT_H
#define TURBOHIKER_TEXT_H

#include "gui_lib.h"
#include "gui_utils.h"
#include "Window.h"

namespace a_gui{
    class Text{
    private:
        sf::Text m_Description;
        sf::Font m_Font;
        std::string m_Text;
        float m_PosX;
        float m_PosY;
    public:
        Text(float xPos, float yPos, std::string text, unsigned int charSize, a_gui::Color textColor, const std::string& fontPath);

        void draw(a_gui::Window* window);

        void addText(std::string text);

    };
}


#endif //TURBOHIKER_TEXT_H
