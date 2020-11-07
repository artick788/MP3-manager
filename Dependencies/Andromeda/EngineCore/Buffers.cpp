//
// Created by arthu on 23/10/2020.
//

#include "Buffers.h"

andromedaCore::ZBuffer::ZBuffer() {
    glEnable(GL_DEPTH_TEST);
}

void andromedaCore::ZBuffer::clear() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

andromedaCore::CullfaceBuffer::CullfaceBuffer(int face) : m_Face(face) {
    glEnable(GL_CULL_FACE);
    glCullFace(face);
}

void andromedaCore::CullfaceBuffer::setCullDirection(int direction) {
    glFrontFace(direction);
}
