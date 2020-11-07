//
// Created by arthu on 05/10/2020.
//

#ifndef ADROMEDA_UTILS_H
#define ADROMEDA_UTILS_H

#include "AndromedaCoreLib.h"

namespace andromedaCore{
    void AdromedaCoreInit();

    bool GLLogCall(const char* function, const char* file, int line);

    int getMaxVertexAttribs();

    int getMaxUBOsize();

    std::string getOpenGLversion();

    void clearOGLerror();

    void checkOGLError();

    void errorCallback(int error, const char* description);

}

#define ASSERT(x) if (!(x));
#define GLCALL(x) andromedaCore::clearOGLerror();\
    x;\
    ASSERT(andromedaCore::GLLogCall(#x, __FILE__, __LINE__))

#endif //ADROMEDA_UTILS_H
