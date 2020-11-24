cmake_minimum_required(VERSION 3.16)
project(MP3_manager)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

if (WIN32)
    include_directories(./Dependencies/SFML-2.5.1/include/)
    file(GLOB SFML_DLL "./Dependencies/SFML-2.5.1/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(./Dependencies/SFML-2.5.1/lib)

    include_directories(./Dependencies/Python37/include/)
    file(GLOB PYTHON_DLL "./Dependencies/Python37/DLLs/*.dll")
    file(COPY ${PYTHON_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(./Dependencies/Python37/libs)
elseif(UNIX)
    message(LIBRARIES_NEEDED)

endif()

set(AGUI_SRC
        Dependencies/AGUI/Window.h
        Dependencies/AGUI/Window.cpp
        Dependencies/AGUI/Button.h
        Dependencies/AGUI/Button.cpp
        Dependencies/AGUI/Text.h
        Dependencies/AGUI/Text.cpp
        Dependencies/AGUI/TextBox.h
        Dependencies/AGUI/TextBox.cpp
        Dependencies/AGUI/gui_lib.h
        Dependencies/AGUI/gui_utils.h
        Dependencies/AGUI/gui_utils.cpp)

add_executable(MP3_manager main.cpp
        ${AGUI_SRC}
        cPython.cpp
        cPython.h
        MediaInfo.cpp
        MediaInfo.h Gui.cpp Gui.h)

set(WIN32_LIBS
        sfml-graphics
        sfml-window
        sfml-system
        python37)

set(UNIX_LIBS
        sfml-graphics
        sfml-window
        sfml-system)

if (WIN32)
    target_link_libraries(MP3_manager ${WIN32_LIBS})
endif()