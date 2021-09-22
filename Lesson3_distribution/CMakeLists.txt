cmake_minimum_required(VERSION 3.20)
project(Lesson3_distribution)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson3_distribution main.cpp headers/State.h headers/DiscreteState.h headers/SetState.h headers/SegmentState.h headers/Unform_distribution.h headers/ProbabilityTest.h headers/libs.h headers/StateEngine.h headers/ContExceptionState.h)
