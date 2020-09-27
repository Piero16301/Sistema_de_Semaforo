cmake_minimum_required(VERSION 3.13)
project(Sistema_Semaforo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lsfml-audio")
set(CMAKE_CXX_FLAGS "-lsfml-graphics")
set(CMAKE_CXX_FLAGS "-lsfml-network")
set(CMAKE_CXX_FLAGS "-lsfml-window")
set(CMAKE_CXX_FLAGS "-lsfml-system")
include_directories(SFML/)

add_executable(Sistema_Semaforo main.cpp SemaforoAuto.cpp SemaforoAuto.h SemaforoPeaton.cpp SemaforoPeaton.h SistemaSemaforo.cpp SistemaSemaforo.h)

target_link_libraries(Sistema_Semaforo -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system)
