cmake_minimum_required(VERSION 3.12)
project(C__Script)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__Script main.cpp jsvalue/jsvalue.h jsvalue/jsvariable.cpp jsvalue/jsvariable.h jsvalue/jsvalue.cpp)