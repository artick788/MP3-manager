//
// Created by arthu on 07/11/2020.
//

#ifndef MP3_MANAGER_CPYTHON_H
#define MP3_MANAGER_CPYTHON_H

#define PY_SSIZE_T_CLEAN
#include <Python.h>

class cPython {
private:
    const char* m_AddModules = "import sys\n"
                             "sys.path.append(\".\")";
public:
    cPython();

    ~cPython();

    void runFile(const char* fileName);

    void runString(const char* command);

};


#endif //MP3_MANAGER_CPYTHON_H
