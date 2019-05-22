cmake_minimum_required(VERSION 3.14)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinearAlgebra
        LLL.inl
        LLL.h
        Matrix.h
        Vector.h
        Tests.cpp
        LLL_Tests.cpp ListVector.h)
