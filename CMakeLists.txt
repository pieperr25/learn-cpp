cmake_minimum_required(VERSION 3.15)
project(LearnCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Each top-level source is one standalone exercise with its own main().
# Discovery is intentional here so new exercises need no build-list maintenance.
# Multi-file projects should use explicit targets in their own subdirectories.
file(GLOB exercise_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
foreach(source IN LISTS exercise_sources)
    get_filename_component(exercise_name "${source}" NAME_WE)
    add_executable("${exercise_name}" "${source}")
    target_include_directories("${exercise_name}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
    if(MSVC)
        target_compile_options("${exercise_name}" PRIVATE /W4)
    else()
        target_compile_options("${exercise_name}" PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
