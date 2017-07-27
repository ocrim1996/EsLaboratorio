cmake_minimum_required(VERSION 3.5)
project(EsLaboratorio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(EsLaboratorio ${SOURCE_FILES})