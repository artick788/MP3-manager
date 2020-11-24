#include "TextBox.h"

a_gui::TextBox::TextBox(float xPos, float yPos, float witdh, float height, a_gui::Color boxColor,
                        const std::string &fontPath, int charSize, a_gui::Color textColor) : m_PosX(xPos),
                                                                                             m_PosY(yPos), m_Width(witdh), m_Height(height), m_IsCLicked(false) {
    m_Box.setSize({m_Width, m_Height});
    m_Box.setPosition(m_PosX, m_PosY);
    m_Box.setFillColor(a_gui::toSfColor(boxColor));
    if (!m_Font.loadFromFile(fontPath)){
        throw std::runtime_error("GUI::TEXTBOX::TEXTBOX::CANNOT_LOAD_FONT");
    }
    else{
        m_Description.setFont(m_Font);
        m_Description.setFillColor(a_gui::toSfColor(textColor));
        m_Description.setCharacterSize(charSize);
        m_Description.setPosition(m_PosX, m_PosY);
    }
}

void a_gui::TextBox::draw(a_gui::Window *window) {
    window->draw(m_Box);
    window->draw(m_Description);
}

void a_gui::TextBox::setClicked() {
    m_IsCLicked = true;
}

bool a_gui::TextBox::determineInBounds(int x, int y) {
    return x >= m_PosX and x <= m_PosX + m_Width and y >= m_PosY and y <= m_PosY + m_Height;
}

bool a_gui::TextBox::mouseIntersects(a_gui::Window *window) {
    int x;
    int y;
    window->getMousePosition(x, y);
    return determineInBounds(x, y);
}

void a_gui::TextBox::isTypedOn(sf::Event &event) {
    if (m_IsCLicked){
        int charTyped = event.text.unicode;
        if (charTyped < 128){
            if (charTyped == KEY_BACKSPACE){
                if (!m_Text.empty()){
                    std::string temp = removeLastChar(m_Text);
                    m_Text = temp;
                    m_Description.setString(temp);
                }
            }
            else if (charTyped == KEY_ENTER){
                m_IsCLicked = false;
            }
            else{
                std::ostringstream ss;
                ss << static_cast<char>(charTyped);
                m_Text += ss.str();
                m_Description.setString(m_Text);
            }
        }
    }
}

std::string a_gui::TextBox::removeLastChar(std::string &input) {
    return input.substr(0, input.size() - 1);
}

const std::string &a_gui::TextBox::getText() const {
    return m_Text;
}

