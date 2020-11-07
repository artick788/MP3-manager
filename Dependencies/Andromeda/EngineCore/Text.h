//
// Created by arthu on 21/10/2020.
//

#ifndef ANDROMEDA_TEXT_H
#define ANDROMEDA_TEXT_H

#include "AndromedaCoreLib.h"
#include "Texture.h"

namespace andromedaCore{
    struct Character {
        Glyph* textureID; // ID handle of the glyph texture
        unsigned int sizeX;         // Size of glyph
        unsigned int sizeY;
        int bearingX;
        int bearingY;      // Offset from baseline to left/top of glyph
        unsigned int advanceX;       // Offset to advance to next glyph
        unsigned int advanceY;
    };

    class Text{
    private:
        std::map<char, Character> m_Library;

    public:
        explicit Text(const std::string& font);

        const std::map<char, Character> &getLibrary() const;
    };

}

#endif //ANDROMEDA_TEXT_H
