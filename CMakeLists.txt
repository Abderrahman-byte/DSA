# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(DSA-Library)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory for headers
include_directories(include)

# Add source files for the library
file(GLOB LIBRARY_SOURCES src/*.cpp)

# Create the library target
add_library(DSA ${LIBRARY_SOURCES})

# Enable testing
enable_testing()

# Add the tests subdirectory
add_subdirectory(tests)
