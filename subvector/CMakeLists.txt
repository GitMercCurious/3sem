cmake_minimum_required(VERSION 3.17)
project(subvector)

set(CMAKE_CXX_STANDARD 17)

add_executable(subvector subvector_profiler.cpp Subvector.h)