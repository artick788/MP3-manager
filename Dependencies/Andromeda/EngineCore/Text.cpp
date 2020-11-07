//
// Created by arthu on 21/10/2020.
//

#include "Text.h"

andromedaCore::Text::Text(const std::string &font) {
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        throw std::runtime_error("ANDROMEDACORE::TEXT::TEXT::CANNOT_INITIALIZE_FREETYPE");
    }
    FT_Face face;
    if (FT_New_Face(ft, font.c_str(), 0, &face)) {
        throw std::runtime_error("ANDROMEDACORE::TEXT::TEXT::FAILED_TO_LOAD_FONT");
    }
    FT_Set_Pixel_Sizes(face, 0, 48);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction
    for (unsigned char c = 0; c < 128; c++)
    {
        // load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            throw std::runtime_error("ANDROMEDACORE::TEXT::TEXT::FAILED_TO_LOAD_GLYPH");
        }
        auto* glyph = new andromedaCore::Glyph(face->glyph->bitmap.width, face->glyph->bitmap.rows, face->glyph->bitmap.buffer);
        unsigned int advance = face->glyph->advance.x;
        Character character = {
                glyph,
                face->glyph->bitmap.width, face->glyph->bitmap.rows,
                face->glyph->bitmap_left, face->glyph->bitmap_top,
                static_cast<unsigned int>(face->glyph->advance.x), static_cast<unsigned int>(face->glyph->advance.y)
        };
        m_Library.insert(std::pair<char, Character>(c, character));
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

}

const std::map<char, andromedaCore::Character> &andromedaCore::Text::getLibrary() const {
    return m_Library;
}
