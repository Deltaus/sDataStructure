cmake_minimum_required(VERSION 3.8)
project(assignment_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cmake-build-debug/header1.h)
add_executable(assignment_6 ${SOURCE_FILES} cmake-build-debug/header1.h)