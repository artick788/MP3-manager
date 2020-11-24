//
// Created by arthu on 10/11/2020.
//

#include "gui_utils.h"

float a_gui::denormalize(float x) {
    return round(x * 255);
}

sf::Color a_gui::toSfColor(a_gui::Color &color) {
    float denR = denormalize(color.red);
    float denG = denormalize(color.green);
    float denB = denormalize(color.blue);
    sf::Color retVal = {static_cast<unsigned char>(denR), static_cast<unsigned char>(denG), static_cast<unsigned char>(denB)};
    return retVal;
}
