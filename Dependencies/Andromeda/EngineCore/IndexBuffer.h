#ifndef ADROMEDA_INDEXBUFFER_H
#define ADROMEDA_INDEXBUFFER_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{
    class IndexBuffer {
    private:
        unsigned int m_RendererID;
        unsigned int m_Size;

    public:
        explicit IndexBuffer(const std::vector<unsigned int> &data);

        explicit IndexBuffer(unsigned int size);

        ~IndexBuffer();

        unsigned int getSize();

        void bind();

        void unbind();

        void setData(unsigned int offset, const std::vector<unsigned int>& data);
    };
}

#endif //ADROMEDA_INDEXBUFFER_H
