//
// Created by arthu on 05/10/2020.
//

#ifndef ADROMEDA_LIBRARY_H
#define ADROMEDA_LIBRARY_H

#ifdef __unix
    #include <GL/glew.h>
#elif __WIN32
    #include <ft2build.h>
    #include FT_FREETYPE_H
    #include <GL/glew.h>
#endif


#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <thread>
#include <stdexcept>
#include <map>

#include "stb_image.h"


#endif //ADROMEDA_LIBRARY_H
