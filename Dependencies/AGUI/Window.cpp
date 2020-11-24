//
// Created by arthu on 10/11/2020.
//

#include "Window.h"

a_gui::Window::Window(unsigned int width, unsigned int height, const std::string &title) : m_Width(width), m_Height(height) {
    m_ContextSettings.depthBits = 24;
    m_ContextSettings.stencilBits = 8;
    m_ContextSettings.antialiasingLevel = 0;
    m_ContextSettings.majorVersion = 3;
    m_ContextSettings.minorVersion = 2;
    m_Context = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Resize | sf::Style::Close, m_ContextSettings);
    m_Context->setActive(true);
    m_View = m_Context->getDefaultView();
    std::cout << m_Context->getSettings().depthBits << std::endl;
}

bool a_gui::Window::isOpen() {
    return m_Context->isOpen();
}

void a_gui::Window::clear() {
    m_Context->clear();
}

void a_gui::Window::setColor(float red, float green, float blue) {
    sf::Color background(denormalize(red), denormalize(green), denormalize(blue));
    m_Context->clear(background);
}

void a_gui::Window::update() {
    m_Context->display();
}

void a_gui::Window::close() {
    m_Context->close();
}

void a_gui::Window::setVerticalSync(bool syncOption) {
    m_Context->setVerticalSyncEnabled(syncOption);
}

bool a_gui::Window::pollEvents(sf::Event& event) {
    return m_Context->pollEvent(event);
}

void a_gui::Window::setIcon(const std::string &icon) {
    sf::Image winIcon;
    winIcon.loadFromFile(icon);
    m_Context->setIcon(winIcon.getSize().x, winIcon.getSize().y, winIcon.getPixelsPtr());
}

void a_gui::Window::draw(sf::Drawable &toDraw) {
    m_Context->draw(toDraw);
}

void a_gui::Window::getMousePosition(int &x, int &y) {
    x = sf::Mouse::getPosition(*m_Context).x;
    y = sf::Mouse::getPosition(*m_Context).y;
}

void a_gui::Window::setFrameLimit(unsigned int limit) {
    m_Context->setFramerateLimit(limit);
}

void a_gui::Window::setBackgroundImage(const std::string &img) {
    m_BackgroundTexture.loadFromFile(img);
    m_Background.setTexture(m_BackgroundTexture);
}

void a_gui::Window::drawBackground() {
    m_Context->draw(m_Background);
}

void a_gui::Window::resize(unsigned int width, unsigned int height) {
    m_Width = width;
    m_Height = height;
    m_View.setSize({static_cast<float>(m_Width), static_cast<float>(m_Height)});
    m_Context->setView(m_View);

}

void a_gui::Window::centerMouse() {
    auto winPos = m_Context->getPosition();
    int mouseX = winPos.x + (m_Width / 2);
    int mouseY = winPos.y + (m_Height / 2);
    sf::Mouse::setPosition({mouseX, mouseY});
}

void a_gui::Window::setWindowPosition(int xPos, int yPos) {
    m_Context->setPosition({xPos, yPos});
}
