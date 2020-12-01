cmake_minimum_required(VERSION 3.10)
project(LearningC++ VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
add_executable(
    myprog
    main.cpp
    lib/math/operations.cpp
    lib/math/operations.hpp
)
