cmake_minimum_required(VERSION 3.16)
project(CLion)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wconversion")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET(CMAKE_CXX_FLAGS -pthread)


add_executable(CLion src/matrizes_sequencial.cpp utils/utils.cpp utils/utils.h src/matrizes_threads.cpp src/criar_matrizes.cpp)
