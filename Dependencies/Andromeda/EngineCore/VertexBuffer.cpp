//
// Created by arthu on 05/10/2020.
//

#include "VertexBuffer.h"


andromedaCore::VertexBuffer::VertexBuffer(const std::vector<float> &vertices) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() *  sizeof(float ), &vertices[0], GL_STATIC_DRAW);
}

andromedaCore::VertexBuffer::VertexBuffer(unsigned int size) {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
}

andromedaCore::VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void andromedaCore::VertexBuffer::setData(unsigned int offset, const std::vector<float> &data) {
    bind();
    glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(float), sizeof(float) * data.size(), &data[0]);
}

void andromedaCore::VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void andromedaCore::VertexBuffer::unBind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}