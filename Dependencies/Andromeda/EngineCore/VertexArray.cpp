#include "VertexArray.h"

andromedaCore::VertexBufferLayout::VertexBufferLayout(unsigned int vertexSize,
                                                      std::vector<unsigned int> &vertexAttribs): s_VertexSize(vertexSize),
                                                      s_VertexAttribs(vertexAttribs){

}

andromedaCore::VertexArray::VertexArray(unsigned int vertexSize) : m_VertexSize(vertexSize), m_VertexAttribPtr(0), m_Offset(0){
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
}

andromedaCore::VertexArray::VertexArray(andromedaCore::VertexBufferLayout *layout) : m_VertexSize(layout->s_VertexSize),
                                                                                     m_VertexAttribPtr(0), m_Offset(0){
    glGenVertexArrays(1, &m_RendererID);
    glBindVertexArray(m_RendererID);
    for (auto& l : layout->s_VertexAttribs){
        glVertexAttribPointer(m_VertexAttribPtr, l, GL_FLOAT, GL_FALSE, m_VertexSize * sizeof(float),
                              reinterpret_cast<const void*>(m_Offset));
        glEnableVertexAttribArray(m_VertexAttribPtr);
        m_VertexAttribPtr += 1;
        m_Offset += l * sizeof(float);
    }

}

andromedaCore::VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_VertexAttribPtr);
}

void andromedaCore::VertexArray::addPointer(unsigned int attribSize) {
    glVertexAttribPointer(m_VertexAttribPtr, attribSize, GL_FLOAT, GL_FALSE, m_VertexSize * sizeof(float),
                          reinterpret_cast<const void*>(m_Offset));
    glEnableVertexAttribArray(m_VertexAttribPtr);
    m_Offset += attribSize * sizeof(float);
    m_VertexAttribPtr += 1;
}

void andromedaCore::VertexArray::bind() {
    glBindVertexArray(m_RendererID);
}

void andromedaCore::VertexArray::unbind() {
    glBindVertexArray(0);
}
