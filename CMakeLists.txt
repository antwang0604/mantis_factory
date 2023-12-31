# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

# Project's name
project(MantisFactory)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# The following folder will be included
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)

# Building Source to Executable
set(
    SOURCES 
    src/main.cpp 
    src/assembly_line.cpp
    src/factory.cpp
    src/helpers.cpp
    src/line_configurator.cpp
    src/station.cpp
)
set (APPNAME "Run${PROJECT_NAME}")
add_executable(${APPNAME} ${SOURCES})