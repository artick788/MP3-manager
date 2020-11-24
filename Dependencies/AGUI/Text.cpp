//
// Created by arthu on 12/11/2020.
//

#include "Text.h"

a_gui::Text::Text(float xPos, float yPos, std::string text, unsigned int charSize, a_gui::Color textColor, const std::string &fontPath):
                m_PosX(xPos), m_PosY(yPos), m_Text(text) {
    if (!m_Font.loadFromFile(fontPath)){
        throw std::runtime_error("GUI::TEXT::CANNOT_OPEN_FONT");
    }
    else{
        m_Description.setFont(m_Font);
        m_Description.setString(text);
        m_Description.setCharacterSize(charSize);
        m_Description.setFillColor(a_gui::toSfColor(textColor));
        m_Description.setPosition(m_PosX, m_PosY);
    }
}

void a_gui::Text::draw(a_gui::Window *window) {
    window->draw(m_Description);
}

void a_gui::Text::addText(std::string text) {
    m_Text += text;
    m_Description.setString(m_Text);
}
