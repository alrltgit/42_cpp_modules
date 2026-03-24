cmake_minimum_required(VERSION 3.20)
project(ex00)

set(CMAKE_CXX_STANDARD 17)

# Make headers in 'includes/' visible
include_directories(${PROJECT_SOURCE_DIR}/includes)

# Add all source files in 'src/'
add_executable(ex00
        main.cpp
        src/ScalarConverter.cpp
        src/TypeDetector.cpp
)