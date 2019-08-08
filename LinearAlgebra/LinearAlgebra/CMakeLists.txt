cmake_minimum_required(VERSION 3.14)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        Manger.cpp
        LLL.cpp
        Tests/Tests.cpp LLL.cpp)


set(CMAKE_C_FLAGS "-lgmp")
target_link_libraries(main gmp gmpxx libgmp)