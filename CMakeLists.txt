cmake_minimum_required(VERSION 3.9)
project(AlgorithmDesign)

set(CMAKE_CXX_STANDARD 11)

add_executable(AlgorithmDesign
        AlgorithmDesign/DynamicProgramming/fibonacci.cpp
        AlgorithmDesign/main.cpp AlgorithmDesign/DynamicProgramming/longest-common-subsequence.cpp AlgorithmDesign/DynamicProgramming/matrix-chain-multiplication.cpp AlgorithmDesign/DynamicProgramming/knapsack.cpp)
