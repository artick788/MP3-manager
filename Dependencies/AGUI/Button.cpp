#include "Button.h"

a_gui::Button::Button(float posX, float posY, float width, float height, a_gui::Color buttonColor)
                    : m_Height(height), m_Width(width), m_PosX(posX), m_PosY(posY), m_ButtonOutline(0.0f) {
    m_Button.setSize({width, height});
    m_Button.setPosition(m_PosX, m_PosY);
    m_Button.setFillColor(a_gui::toSfColor(buttonColor));
}

void a_gui::Button::draw(a_gui::Window* window) {
    window->draw(m_Button);
    window->draw(m_Description);
}

void a_gui::Button::addText(std::string text, unsigned int charSize, a_gui::Color textColor, const std::string& fontPath) {
    if (!m_Font.loadFromFile(fontPath)){
        throw std::runtime_error("GUI::BUTTON::ADDTEXT::CANNOT_OPEN_FONT");
    }
    else{
        m_Description.setFont(m_Font);
        m_Description.setString(text);
        m_Description.setCharacterSize(charSize);
        m_Description.setFillColor(a_gui::toSfColor(textColor));
        float xPos = m_PosX;
        float yPos = m_PosY;
        m_Description.setPosition(xPos, yPos);
    }
}

bool a_gui::Button::mouseIntersects(a_gui::Window *window) {
    int x;
    int y;
    window->getMousePosition(x, y);
    return determineInBounds(x, y);
}

bool a_gui::Button::determineInBounds(int x, int y) {
    return x >= m_PosX - m_ButtonOutline and x <= m_PosX + m_Width + m_ButtonOutline and y >= m_PosY - m_ButtonOutline and y <= m_PosY + m_Height + m_ButtonOutline;
}

void a_gui::Button::setBorder(float thickness, a_gui::Color color) {
    m_Button.setOutlineThickness(thickness);
    m_Button.setOutlineColor(a_gui::toSfColor(color));
    m_ButtonOutline = thickness;

}

void a_gui::Button::setPressed(float offset) {
    float thickness = m_ButtonOutline - offset;
    if (thickness < 0){
        throw std::runtime_error("GUI::BUTTON::SETPRESSED::INVALID_OFFSET");
    }
    m_Button.setOutlineThickness(thickness);
}

void a_gui::Button::setReleased() {
    m_Button.setOutlineThickness(m_ButtonOutline);
}
