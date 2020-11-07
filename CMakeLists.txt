cmake_minimum_required(VERSION 3.16)
project(MP3_manager)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

if (WIN32)
    include_directories(./Dependencies/WIN32/glfw-3.3.2/include/)
    file(GLOB GLFW_DLL "./Dependencies/WIN32/glfw-3.3.2/lib-mingw-w64/*.dll")
    file(COPY ${GLFW_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(./Dependencies/WIN32/glfw-3.3.2/lib-mingw-w64/)

    include_directories(./Dependencies/WIN32/glew-2.1.0/include/)
    file(GLOB GLEW_DLL "./Dependencies/WIN32/glew-2.1.0/bin/Release/x64/*.dll")
    file(COPY ${GLEW_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(./Dependencies/WIN32/glew-2.1.0/lib/Release/x64/)

    include_directories(./Dependencies/WIN32/freetype/include/)
    file(GLOB FREETYPE_DLL "./Dependencies/WIN32/freetype/win64/*.dll")
    file(COPY ${FREETYPE_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(./Dependencies/WIN32/freetype/win64/)

elseif(UNIX)
    message(LIBRARIES_NEEDED)

endif()

set(ANDROMEDA_CORE_SRC
        ${GLEW_SRC}
        Dependencies/Andromeda/EngineCore/AndromedaCoreLib.h
        Dependencies/Andromeda/EngineCore/CoreUtils.h
        Dependencies/Andromeda/EngineCore/CoreUtils.cpp
        Dependencies/Andromeda/EngineCore/VertexBuffer.cpp
        Dependencies/Andromeda/EngineCore/VertexBuffer.h
        Dependencies/Andromeda/EngineCore/IndexBuffer.cpp
        Dependencies/Andromeda/EngineCore/IndexBuffer.h
        Dependencies/Andromeda/EngineCore/VertexArray.cpp
        Dependencies/Andromeda/EngineCore/VertexArray.h
        Dependencies/Andromeda/EngineCore/Shader.cpp
        Dependencies/Andromeda/EngineCore/Shader.h
        Dependencies/Andromeda/EngineCore/Renderer.cpp
        Dependencies/Andromeda/EngineCore/Renderer.h
        Dependencies/Andromeda/EngineCore/stb_image.cpp
        Dependencies/Andromeda/EngineCore/stb_image.h
        Dependencies/Andromeda/EngineCore/Texture.cpp
        Dependencies/Andromeda/EngineCore/Texture.h
        Dependencies/Andromeda/EngineCore/Text.cpp
        Dependencies/Andromeda/EngineCore/Text.h
        Dependencies/Andromeda/EngineCore/Buffers.cpp
        Dependencies/Andromeda/EngineCore/Buffers.h
        Dependencies/Andromeda/EngineCore/Andromeda.h)

set(ANDROMEDA_SRC
        ${ANDROMEDA_CORE_SRC}
        Dependencies/Andromeda/Window.h
        Dependencies/Andromeda/Window.cpp
        Dependencies/Andromeda/AndromedaUtils.cpp
        Dependencies/Andromeda/AndromedaUtils.h
        Dependencies/Andromeda/AndromedaLib.h
        Dependencies/Andromeda/Camera.cpp
        Dependencies/Andromeda/Camera.h
        Dependencies/Andromeda/ini_parser.h
        Dependencies/Andromeda/ini_parser.cpp
        Dependencies/Andromeda/Model.h
        Dependencies/Andromeda/Model.cpp)

include_directories(./Dependencies/glm/)

add_executable(MP3_manager main.cpp Library.h)

set(WIN32_LIBS
        -lopenGL32
        -lglfw3
        -lglew32
        -lfreetype)

set(UNIX_LIBS
        -lGL
        -lGLEW
        -lglfw
        -lfreetype)

if (WIN32)
    target_link_libraries(MP3_manager ${WIN32_LIBS})
endif()