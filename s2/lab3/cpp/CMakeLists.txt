cmake_minimum_required(VERSION 3.21)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp main.cpp Equation.cpp Equation.h EqList.cpp EqList.h Outputter.cpp Outputter.h func.cpp func.h)
