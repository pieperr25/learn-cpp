cmake_minimum_required(VERSION 3.15)
project(LearnCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(file1
    function_testing.cpp
)

add_executable(file2
    console_input_output.cpp
)
