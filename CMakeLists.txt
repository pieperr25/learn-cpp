cmake_minimum_required(VERSION 3.15)
project(LearnCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Both files belong to one program: only dual_file1.cpp defines main().
add_executable(app
    dual_file/dual_file1.cpp
    dual_file/dual_file2.cpp
)

# lesson-2_final-1.cpp and io.cpp belong to one program: only
# lesson-2_final-1.cpp defines main().
add_executable(lesson-2_final-1
    lesson-2_final-1/lesson-2_final-1.cpp
    lesson-2_final-1/io.cpp
)

# Each top-level source in src/ is a standalone exercise with its own main().
# Discovery is intentional so new exercises need no build-list maintenance.
file(GLOB exercise_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(exercise_targets app lesson-2_final-1)
foreach(source IN LISTS exercise_sources)
    get_filename_component(exercise_name "${source}" NAME_WE)
    add_executable("${exercise_name}" "${source}")
    list(APPEND exercise_targets "${exercise_name}")
endforeach()

foreach(exercise_name IN LISTS exercise_targets)
    target_include_directories("${exercise_name}" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
    if(MSVC)
        target_compile_options("${exercise_name}" PRIVATE /W4)
    else()
        target_compile_options("${exercise_name}" PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
