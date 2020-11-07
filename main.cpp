#include <iostream>
#include "cPython.h"

int main() {
    try {
        cPython pyRunner;
        pyRunner.runFile("./Runner.py");

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "error" << std::endl;
    }
    return 0;
}