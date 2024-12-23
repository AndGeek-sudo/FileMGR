cmake_minimum_required(VERSION 3.10)

project(FileMGR VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)

add_subdirectory(src)