cmake_minimum_required(VERSION 3.17)
project(test_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(subvector main.cpp subvector.h container.h stack.h)