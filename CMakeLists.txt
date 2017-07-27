cmake_minimum_required(VERSION 3.5)
project(EsLaboratorio)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_PREFIX_PATH "/Users/mircoceccarelli/Qt/5.9.1/clang_64/lib/cmake/Qt5Widgets/")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

add_subdirectory(test)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp Observer.h Subject.h File.cpp File.h LoadResources.cpp LoadResources.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/mircoceccarelli/ClionProjects/EsLaboratorio/risorse")
add_executable(EsLaboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(core Qt5::Widgets)
target_link_libraries(EsLaboratorio core)