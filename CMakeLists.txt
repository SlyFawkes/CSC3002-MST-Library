cmake_minimum_required(VERSION 3.8)
project(SolvingLibrary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES library.cpp library.h AbstractSolver.h DataStructures/FibonacciHeap.cpp DataStructures/FibonacciHeap.h PrimSolver.cpp PrimSolver.h DataStructures/Node.cpp DataStructures/Node.h)
add_library(SolvingLibrary ${SOURCE_FILES})