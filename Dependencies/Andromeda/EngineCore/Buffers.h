//
// Created by arthu on 23/10/2020.
//

#ifndef ANDROMEDA_BUFFERS_H
#define ANDROMEDA_BUFFERS_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{
    class ZBuffer{
    public:
        ZBuffer();

        void clear();
    };

    class CullfaceBuffer{
    private:
        int m_Face;
        int m_Direction;

    public:
        explicit CullfaceBuffer(int face);

        void setCullDirection(int direction);


    };

}


#endif //ANDROMEDA_BUFFERS_H
