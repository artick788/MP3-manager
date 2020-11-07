#ifndef ADROMEDA_VERTEXBUFFER_H
#define ADROMEDA_VERTEXBUFFER_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{
    class VertexBuffer{
    private:
        unsigned int m_RendererID;

    public:
        explicit VertexBuffer(const std::vector<float> &vertices);

        explicit VertexBuffer(unsigned int size);

        ~VertexBuffer();

        void setData(unsigned int offset, const std::vector<float>& data);

        void bind();

        void unBind();
    };

}

#endif //ADROMEDA_VERTEXBUFFER_H
