cmake_minimum_required(VERSION 3.14)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinearAlgebra
        ListVector.h
        Tests.h
        Tests.cpp VectorTests.cpp)


set(CMAKE_C_FLAGS "-lgmp")
target_link_libraries(LinearAlgebra gmp gmpxx libgmp)