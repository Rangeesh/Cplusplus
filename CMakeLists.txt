cmake_minimum_required(VERSION 3.10)
project(LearningC++ VERSION 1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# message(${CMAKE_BINARY_DIR}) # From where I'm running cmake.
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/)
add_subdirectory(lib/math)
add_executable(
    myprog
    main.cpp
)
target_link_libraries(myprog math)
