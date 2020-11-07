//
// Created by arthu on 07/11/2020.
//

#include "cPython.h"

cPython::cPython() {
    Py_Initialize();
    runString(m_AddModules);
}

cPython::~cPython() {
    Py_Finalize();
}

void cPython::runFile(const char *fileName) {
    PyObject *obj = Py_BuildValue("s", fileName);
    FILE *file = _Py_fopen_obj(obj, "r+");
    if(file != NULL) {
        PyRun_SimpleFile(file, fileName);
    }
}

void cPython::runString(const char* command) {
    PyRun_SimpleString(command);
}
