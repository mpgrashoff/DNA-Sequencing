cmake_minimum_required(VERSION 3.27)
project(DNA_sequencing)

set(CMAKE_CXX_STANDARD 17)

add_executable(DNA_sequencing main.cpp
        NWAlgo.cpp
        NWAlgo.h
        SubstitutionMatrix.h)
