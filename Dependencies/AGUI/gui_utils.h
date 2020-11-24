//
// Created by arthu on 10/11/2020.
//

#ifndef TURBOHIKER_GUI_UTILS_H
#define TURBOHIKER_GUI_UTILS_H

#include "gui_lib.h"

namespace a_gui{
    float denormalize(float x);

    struct Color{
        float red;
        float green;
        float blue;
    };

    sf::Color toSfColor(Color& color);
}

#endif //TURBOHIKER_GUI_UTILS_H
