cmake_minimum_required(VERSION 3.23)
project(tee_shirt_song)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(tee_shirt_song
        src/logic.hpp
        src/instru.cpp
        src/main.cpp)
