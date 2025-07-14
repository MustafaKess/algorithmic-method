cmake_minimum_required(VERSION 3.22)
project(algorithmic_method_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(sorting-algorithms)

add_executable(algorithmic_method_main
    sorting-algorithms/QuickSort.cc
    sorting-algorithms/QuickSort.h)
