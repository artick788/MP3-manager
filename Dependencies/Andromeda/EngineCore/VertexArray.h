//
// Created by arthu on 05/10/2020.
//

#ifndef ADROMEDA_VERTEXARRAY_H
#define ADROMEDA_VERTEXARRAY_H

#include "AndromedaCoreLib.h"
#include "CoreUtils.h"

namespace andromedaCore{
    struct VertexBufferLayout{
        unsigned int s_VertexSize;
        std::vector<unsigned int> s_VertexAttribs;

        VertexBufferLayout(unsigned int vertexSize, std::vector<unsigned int>& vertexAttribs);
    };

    class VertexArray{
    private:
        unsigned int m_RendererID;

        unsigned int m_VertexSize;
        unsigned int m_Offset;
        unsigned int m_VertexAttribPtr;

        VertexBufferLayout* m_Layout;

    public:
        explicit VertexArray(unsigned int vertexSize);

        explicit VertexArray(VertexBufferLayout* layout);

        ~VertexArray();

        void addPointer(unsigned int attribSize);

        void bind();

        void unbind();

    };

}

#endif //ADROMEDA_VERTEXARRAY_H
