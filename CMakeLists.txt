cmake_minimum_required(VERSION 3.30)
project(dz)

set(CMAKE_CXX_STANDARD 20)

add_executable(dz main.cpp
        dzD.cpp dzD.h
        dzC.cpp dzC.h
        dz3.cpp dz3.h
        dzH.cpp dzH.h
        dzG.cpp dzG.h
)
