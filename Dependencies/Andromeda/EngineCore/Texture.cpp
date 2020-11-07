//
// Created by arthu on 10/10/2020.
//

#include "Texture.h"

void andromedaCore::TextureBase::genTextures(int dimmension) {
    m_Dimmension = dimmension;
    glGenTextures(1, &m_RendererID);
    glBindTexture(m_Dimmension, m_RendererID);
}

void andromedaCore::TextureBase::bind(unsigned int offset) {
    glActiveTexture(GL_TEXTURE0 + offset);
    glBindTexture(m_Dimmension, m_RendererID);
}

void andromedaCore::TextureBase::unbind() {
    glBindTexture(m_Dimmension, 0);
}

void andromedaCore::TextureBase::setParameter(int name, int method) {
    glTexParameteri(m_Dimmension, name, method);
}

void andromedaCore::TextureBase::loadFromFile(const char *file) {
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(file, &m_Width, &m_Height, &m_NrChannels, 4);
    if (data){
        glTexImage2D(m_Dimmension, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(m_Dimmension);
    }
    else{
        throw std::runtime_error("ANDROMEDACORE::TEXTURE::GENTEXTURES::UNABLE_TO_LOAD_TEXTURE");
    }
    stbi_image_free(data);

}

void andromedaCore::TextureBase::setTexture(unsigned char *data) const {
    glTexImage2D(m_Dimmension, 0, GL_RED, m_Width, m_Height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
}

andromedaCore::Texture1D::Texture1D(const std::string &texFile) {
    genTextures(GL_TEXTURE_1D);
    loadFromFile(texFile.c_str());
    setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
    setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

andromedaCore::Texture2D::Texture2D(const std::string &texFile) {
    genTextures(GL_TEXTURE_2D);
    loadFromFile(texFile.c_str());
    setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
    setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

andromedaCore::Texture3D::Texture3D(const std::string &texFile) {
    genTextures(GL_TEXTURE_3D);
    loadFromFile(texFile.c_str());
    setParameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
    setParameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
    setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

andromedaCore::TextureCube::TextureCube(const std::string &texFile) {
    genTextures(GL_TEXTURE_CUBE_MAP);
    loadFromFile(texFile.c_str());
}

andromedaCore::Glyph::Glyph(int width, int height, unsigned char *data) {
    genTextures(GL_TEXTURE_2D);
    m_Width = width;
    m_Height = height;
    setTexture(data);
    setParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    setParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    setParameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void andromedaCore::Glyph::explicitBind() {
    bind(m_RendererID);
}
