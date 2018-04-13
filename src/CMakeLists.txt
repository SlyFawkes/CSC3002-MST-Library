cmake_minimum_required(VERSION 3.5)
project(SolvingLibrary)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES DataStructures/FibonacciHeap.cpp DataStructures/FibonacciHeap.h PrimSolver.cpp PrimSolver.h DataStructures/Node.cpp DataStructures/Node.h KruskalSolver.cpp KruskalSolver.h)
add_library(SolvingLibrary STATIC ${SOURCE_FILES})