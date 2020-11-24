//
// Created by arthu on 24/11/2020.
//

#include "Gui.h"

mp3_manager::GUI::GUI() {
    m_Window = new a_gui::Window(800, 600, "MP3_MANAGER");
    m_Window->setVerticalSync(true);
    m_Choice = WindowChoice::MENU;
}

void mp3_manager::GUI::run() {
    while (m_Window->isOpen()){
        if (m_Choice == WindowChoice::CLOSED){
            m_Window->close();
        }
        else if (m_Choice == WindowChoice::MENU){
            menuScreen();
        }
        else if (m_Choice == WindowChoice::MP3_TAGGER){
            MP3_TaggerScreen();
        }
    }

}

void mp3_manager::GUI::menuScreen() {
    const std::string arial = "./Resources/Fonts/arial.ttf";
    a_gui::Text title(100.0f, 50.0f, "Welcome to MP3 Manager", 50, {0.0f, 0.0f, 0.0f}, arial);
    a_gui::Button tagger(200.0f, 200.0f, 200.0f, 50.0f, {0.8f, 0.8f, 0.1f});
    tagger.addText("Edit MP3 tags", 24, {0.0f, 0.0f, 0.0f}, arial);
    tagger.setBorder(10.0f, {0.1f, 0.2f, 0.3f});

    while (m_Choice == WindowChoice::MENU){
        m_Window->clear();
        m_Window->setColor(0.1f, 0.45f, 0.1f);

        sf::Event event{};
        while (m_Window->pollEvents(event)){
            if (event.type == sf::Event::Closed){
                m_Choice = WindowChoice::CLOSED;
            }
            if (tagger.mouseIntersects(m_Window) and event.type == sf::Event::MouseButtonPressed){
                tagger.setPressed(5.0f);
                m_Choice = WindowChoice::MP3_TAGGER;
            }
            if (tagger.mouseIntersects(m_Window) and event.type == sf::Event::MouseButtonReleased){
                tagger.setReleased();
            }
        }

        tagger.draw(m_Window);
        title.draw(m_Window);

        m_Window->update();
    }

}

void mp3_manager::GUI::MP3_TaggerScreen() {
    const std::string arial = "./Resources/Fonts/arial.ttf";
    a_gui::Text title(100.0f, 50.0f, "Edit Metadata of Your MP3's", 50, {0.0f, 0.0f, 0.0f}, arial);
    a_gui::TextBox artistName(200.0f, 200.0f, 200.0f, 50.0f, {0.8f, 0.8f, 0.1f}, arial, 24, {0.0f, 0.0f, 0.0f});
    a_gui::Button menu(50.0f, 500.0f, 200.0f, 50.0f, {0.8f, 0.8f, 0.1f});


    menu.addText("return to menu", 24, {0.0f, 0.0f, 0.0f}, arial);
    menu.setBorder(10.0f, {0.1f, 0.2f, 0.3f});

    while (m_Choice == WindowChoice::MP3_TAGGER){
        m_Window->clear();
        m_Window->setColor(0.1f, 0.45f, 0.1f);

        sf::Event event{};
        while (m_Window->pollEvents(event)){
            if (event.type == sf::Event::Closed){
                m_Choice = WindowChoice::CLOSED;
            }
            if (menu.mouseIntersects(m_Window) and event.type == sf::Event::MouseButtonPressed){
                menu.setPressed(5.0f);
                m_Choice = WindowChoice::MENU;
            }
            if (menu.mouseIntersects(m_Window) and event.type == sf::Event::MouseButtonReleased){
                menu.setReleased();
            }
            else if (event.type == sf::Event::MouseButtonPressed and artistName.mouseIntersects(m_Window)){
                artistName.setClicked();
            }
            else if (event.type == sf::Event::TextEntered){
                artistName.isTypedOn(event);
            }
        }

        title.draw(m_Window);
        menu.draw(m_Window);
        artistName.draw(m_Window);


        m_Window->update();
    }
}
