cmake_minimum_required(VERSION 4.2)
project(awosome_algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(awosome_algorithm
#        src/floyd_warshall.cpp
        src/prim.cpp
        src/matrix_chain_multiplication.cpp)
