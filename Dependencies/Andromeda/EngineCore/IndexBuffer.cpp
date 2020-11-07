//
// Created by arthu on 05/10/2020.
//

#include "IndexBuffer.h"

andromedaCore::IndexBuffer::IndexBuffer(const std::vector<unsigned int> &data): m_Size(data.size()) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    unsigned int size = sizeof(unsigned int) * m_Size;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
}

andromedaCore::IndexBuffer::IndexBuffer(unsigned int size){
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), nullptr, GL_DYNAMIC_DRAW);

}

andromedaCore::IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void andromedaCore::IndexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void andromedaCore::IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int andromedaCore::IndexBuffer::getSize() {
    return m_Size;
}

void andromedaCore::IndexBuffer::setData(unsigned int offset, const std::vector<unsigned int> &data) {
    bind();
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset * sizeof(unsigned int), sizeof(unsigned int) * data.size(), &data[0]);
}

