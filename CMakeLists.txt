cmake_minimum_required(VERSION 3.15)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# List every .cpp file you want to compile here
add_executable(app
    dual_file1.cpp
    dual_file2.cpp
)

add_executable(function_test
    function_testing.cpp
)

add_executable(cin_cout
    console_input_output.cpp
)