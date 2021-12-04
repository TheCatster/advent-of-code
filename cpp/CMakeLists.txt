cmake_minimum_required(VERSION 3.15)
project(advent-of-code-cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -g)

set(HEADER_FILES ${PROJECT_SOURCE_DIR}/inc/advent-of-code.h)

add_library(advent-of-code lib/advent-of-code.cpp ${HEADER_FILES})
target_include_directories(advent-of-code PRIVATE inc)

add_subdirectory(src)
