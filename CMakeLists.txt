cmake_minimum_required(VERSION 3.30)
project(dz)
# Находим SFML
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Добавляем SFML к твоему исполняемому файлу
target_link_libraries(dz PRIVATE sfml-graphics sfml-window sfml-system)

set(CMAKE_CXX_STANDARD 20)

add_executable(dz main.cpp
        dzA.cpp dzA.h
        dzB.cpp dzB.h
        dzC.cpp dzC.h
        dzD.cpp dzD.h
        dzE.cpp dzE.h
        dzF.cpp dzF.h
        dzG.cpp dzG.h
        dzH.cpp dzH.h
        dzI.cpp dzI.h
        dzJ.cpp dzJ.h
)
