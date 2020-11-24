//
// Created by arthu on 24/11/2020.
//

#ifndef MP3_MANAGER_GUI_H
#define MP3_MANAGER_GUI_H

#include "Dependencies/AGUI/Window.h"
#include "Dependencies/AGUI/Button.h"
#include "Dependencies/AGUI/TextBox.h"
#include "Dependencies/AGUI/Text.h"


namespace mp3_manager{
    enum class WindowChoice{
        CLOSED = 0,
        MENU = 1,
        MP3_TAGGER = 2
    };

    class GUI{
    private:
        a_gui::Window* m_Window;
        WindowChoice m_Choice;

        void menuScreen();

        void MP3_TaggerScreen();

    public:
        GUI();

        void run();
    };

}

#endif //MP3_MANAGER_GUI_H
