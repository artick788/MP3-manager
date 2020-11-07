//
// Created by arthu on 07/10/2020.
//

#include "Renderer.h"

andromedaCore::Renderer::Renderer() {}

andromedaCore::Renderer::Renderer(const std::vector<float> &data, andromedaCore::VertexBufferLayout *layout,
                                  andromedaCore::Shader *shader) : m_Shader(shader), m_VerticesCount(data.size()) {
    m_VBO = new VertexBuffer(data);
    m_VAO = new VertexArray(layout);
    m_VBO->bind();

}

andromedaCore::Renderer::Renderer(const std::vector<float> &data, const std::vector<unsigned int> &indices,
                                  andromedaCore::VertexBufferLayout *layout, andromedaCore::Shader *shader) : m_Shader(shader),
                                                                                                              m_VerticesCount(data.size()){

    m_VBO = new VertexBuffer(data);
    m_IBO = new IndexBuffer(indices);
    m_VAO = new VertexArray(layout);
    m_VBO->bind();
    m_IBO->bind();
}

void andromedaCore::Renderer::drawArrays(unsigned int drawMode) {
    m_Shader->bind();
    m_VAO->bind();
    glDrawArrays(drawMode, 0, m_VerticesCount);
}

void andromedaCore::Renderer::drawElements(unsigned int drawMode) {
    m_Shader->bind();
    m_VAO->bind();
    glDrawElements(drawMode, m_IBO->getSize(), GL_UNSIGNED_INT, nullptr);
}

andromedaCore::DynamicRenderer::DynamicRenderer(unsigned int vboSize, VertexBufferLayout* layout, Shader* shader) {
    m_Shader = shader;
    m_SizeVBO = vboSize;
    m_VBO = new VertexBuffer(m_SizeVBO);
    m_VAO = new VertexArray(layout);
}

andromedaCore::DynamicRenderer::DynamicRenderer(unsigned int vboSize, unsigned int iboSize,
                                                andromedaCore::VertexBufferLayout *layout,
                                                andromedaCore::Shader *shader) {
    m_Shader = shader;
    m_SizeVBO = vboSize;
    m_IBO = new IndexBuffer(iboSize);
    m_VBO = new VertexBuffer(m_SizeVBO);
    m_VAO = new VertexArray(layout);
}

void andromedaCore::DynamicRenderer::drawArrays(unsigned int drawMode, unsigned int offset, const std::vector<float> &data) {
    m_VBO->setData(offset, data);
    m_Shader->bind();
    m_VAO->bind();
    glDrawArrays(drawMode, 0, data.size());

}

void andromedaCore::DynamicRenderer::drawElements(unsigned int drawMode, unsigned int vboOffset,
                                                  const std::vector<float> &vertices, unsigned int iboOffset,
                                                  const std::vector<unsigned int> &indices) {
    m_IBO->setData(iboOffset, indices);
    m_VBO->setData(vboOffset, vertices);
    m_Shader->bind();
    m_VAO->bind();
    glDrawElements(drawMode, m_IBO->getSize(), GL_UNSIGNED_INT, nullptr);
}

andromedaCore::TextRenderer::TextRenderer(const std::string &font, andromedaCore::Shader *shader) {
    m_Shader = shader;
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_VBO = new VertexBuffer(sizeof(float) * 6 * 4);
    m_VAO = new VertexArray(4);
    m_VAO->addPointer(4);
    m_TextID = new Text(font);
    m_VBO->bind();
}


void andromedaCore::TextRenderer::draw(const std::string &text, float xPos, float yPos, float scale) {
    m_VAO->bind();
    m_Shader->bind();
    float oldX = xPos;
    std::string::const_iterator c;
    std::map<char, andromedaCore::Character> characters = m_TextID->getLibrary();
    for (c = text.begin(); c != text.end(); c++){
        if (*c == '\n'){
            yPos -=(2048 >> 5) * scale ;
            xPos = oldX;
            continue;
        }
        Character ch = characters[*c];

        float xpos = xPos + ch.bearingX * scale;
        float ypos = yPos - (ch.sizeY - ch.bearingY) * scale;
        float w = ch.sizeX * scale;
        float h = ch.sizeY * scale;
        std::vector<float> vertices = {
                xpos,     ypos + h,   0.0f, 0.0f ,
                xpos,     ypos,       0.0f, 1.0f ,
                xpos + w, ypos,       1.0f, 1.0f ,

                xpos,     ypos + h,   0.0f, 0.0f ,
                xpos + w, ypos,       1.0f, 1.0f ,
                xpos + w, ypos + h,   1.0f, 0.0f
        };
        ch.textureID->bind(0);
        m_VBO->setData(0, vertices);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        xPos += (ch.advanceX >> 6) * scale;
    }
}
