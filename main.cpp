#include <iostream>
#include "cPython.h"
#include "MediaInfo.h"
#include "Gui.h"

int main() {
    try {
        mp3_manager::GUI gui;
        gui.run();

//        cPython pyRunner;
//        MediaInfo info("./tests/test.mp3", "D:\\Cache\\");
//        info.setName("Wiley Flow");
//        info.setAlbum("none");
//        info.setArtist("Stormzy");
//        info.setNr(1);
//        info.writeBack();
//        pyRunner.runFile("./Runner.py");

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "error" << std::endl;
    }
    return 0;
}