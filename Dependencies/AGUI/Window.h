//
// Created by arthu on 10/11/2020.
//

#ifndef TURBOHIKER_WINDOW_H
#define TURBOHIKER_WINDOW_H

#include "gui_lib.h"
#include "gui_utils.h"
#include <iostream>

namespace a_gui{
    class Window{
    private:
        unsigned int m_Height;
        unsigned int m_Width;
        sf::VideoMode m_VideoMode;
        sf::RenderWindow* m_Context;
        sf::Texture m_BackgroundTexture;
        sf::Sprite m_Background;
        sf::View m_View;
        sf::ContextSettings m_ContextSettings;

    public:
        Window(unsigned int width, unsigned int height, const std::string& title);

        bool isOpen();

        void clear();

        void setColor(float red, float green, float blue);

        void update();

        void close();

        void setVerticalSync(bool syncOption);

        bool pollEvents(sf::Event& event);

        void setIcon(const std::string& icon);

        void draw(sf::Drawable &toDraw);

        void getMousePosition(int& x, int& y);

        void centerMouse();

        void setFrameLimit(unsigned int limit);

        void setBackgroundImage(const std::string& img);

        void drawBackground();

        void resize(unsigned int width, unsigned int height);

        void setWindowPosition(int xPos, int yPos);
    };
}

#endif //TURBOHIKER_WINDOW_H
