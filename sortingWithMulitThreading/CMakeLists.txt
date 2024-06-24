cmake_minimum_required(VERSION 3.26)
project(sortingWithMulitThreading CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(SDL2_PATH "C:/Users/Dante/Downloads/SDL2-devel-2.30.4-mingw/SDL2-2.30.4/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(sortingWithMulitThreading main.cpp
        soringAlghoritms.cpp
        decleration.h
        printing/printingVisual.cpp
        printing/printingVisualEss.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
