cmake_minimum_required(VERSION 3.15)
project(Pr5)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Pr5
        src/AnalizadorER.cpp
        src/AnalizadorER.h
        src/ER2Tree.cpp
        src/NodoB.h)
