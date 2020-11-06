cmake_minimum_required(VERSION 3.16)
project(MP3_manager)

set(CMAKE_CXX_STANDARD 14)

add_executable(MP3_manager Application.cpp ${ID3LIB_SRC})
add_executable(MP3_test main.cpp)