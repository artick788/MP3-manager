//
// Created by arthu on 10/10/2020.
//

#ifndef ANDROMEDA_TEXTURE_H
#define ANDROMEDA_TEXTURE_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{

    class TextureBase{
    private:
        int m_Dimmension;
    protected:
        unsigned int m_RendererID;
        int m_Width;
        int m_Height;
        int m_NrChannels;

        void genTextures(int dimmension);

        void loadFromFile(const char* file);

        void setTexture(unsigned char* data) const;

    public:
        void bind(unsigned int offset);

        void unbind();

        void setParameter(int name, int method);
    };

    class Texture1D: public TextureBase{
    public:
        explicit Texture1D(const std::string& texFile);
    };

    class Texture2D: public TextureBase{
    public:
        explicit Texture2D(const std::string& texFile);
    };

    class Texture3D: public TextureBase{
    public:
        explicit Texture3D(const std::string& texFile);
    };

    class TextureCube: public TextureBase{
    public:
        explicit TextureCube(const std::string& texFile);
    };

    class Glyph: public TextureBase{
    public:
        Glyph(int width, int height, unsigned char* data);

        void explicitBind();

    };
}


#endif //ANDROMEDA_TEXTURE_H
