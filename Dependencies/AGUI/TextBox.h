//
// Created by arthu on 12/11/2020.
//

#ifndef TURBOHIKER_TEXTBOX_H
#define TURBOHIKER_TEXTBOX_H

#include "gui_lib.h"
#include "gui_utils.h"
#include "Window.h"

#ifdef __WIN32
    #define KEY_BACKSPACE       0x08
    #define KEY_ENTER           0x0D
    #define KEY_ESCAPE          0x1B
#elif __WIN64
    #define KEY_BACKSPACE       0x08
    #define KEY_ENTER           0x0D
    #define KEY_ESCAPE          0x1B
#elif  __unix
    #define KEY_BACKSPACE       0x08
    #define KEY_ENTER           0x0D
    #define KEY_ESCAPE          0x1B

#endif
namespace a_gui{
    class TextBox{
    private:
        sf::Text m_Description;
        sf::RectangleShape m_Box;
        sf::Font m_Font;
        float m_Width;
        float m_Height;
        float m_PosX;
        float m_PosY;
        bool m_IsCLicked;

        std::string m_Text;

        static std::string removeLastChar(std::string& input);

        bool determineInBounds(int x, int y);
    public:
        TextBox(float xPos, float yPos, float witdh, float height, a_gui::Color boxColor, const std::string& fontPath, int charSize, a_gui::Color textColor);

        void draw(a_gui::Window* window);

        void setClicked();

        bool mouseIntersects(a_gui::Window* window);

        void isTypedOn(sf::Event& event);

        const std::string &getText() const;


    };
}


#endif //TURBOHIKER_TEXTBOX_H
