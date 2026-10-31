# Learning C++

[![Build C++](https://github.com/pieperr25/learn-cpp/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/pieperr25/learn-cpp/actions/workflows/build.yml)

My C++ practice repository as I work through [LearnCpp](https://www.learncpp.com/).
It records small exercises and my learning notes as I build a foundation in C++17.

## What is here

- Console input and output using `std::cin` and `std::cout`.
- Functions, parameters, and return values.
- A [header declaration and include guard](include/add.h) (declaration practice; the function is not implemented yet).
- [Learning notes](written-progress/) from my practice sessions.
- A [Python practice tracker](tracker/README.md) with Mac and Windows setup scripts.

These are learning exercises in progress. Each executable is a separate program.

## Exercises

[Browse all exercises in `src/`](src/) — GitHub lists the current files automatically.
New files appear here when they are pushed, with no manual index to maintain.
Headers live in [`include/`](include/).

The two-file exercise, [`dual_file1.cpp`](dual_file1.cpp) and
[`dual_file2.cpp`](dual_file2.cpp), builds together as `app`.

## Build

You need CMake 3.15 or newer and a C++17 compiler (GCC, Clang, or MSVC).

```sh
git clone https://github.com/pieperr25/learn-cpp.git
cd learn-cpp
cmake -S . -B build
cmake --build build --config Debug
```

Build output stays in `build/`, which Git ignores.

Run an exercise on macOS or Linux:

```sh
./build/function_testing
./build/console_input_output
./build/app
```

With the default Visual Studio generator on Windows (PowerShell):

```powershell
.\build\Debug\function_testing.exe
.\build\Debug\console_input_output.exe
.\build\Debug\app.exe
```

## Adding an exercise

Save a new standalone program as `src/exercise_name.cpp`, with its own `main()`.
CMake picks it up automatically and names the executable `exercise_name`.
Save headers in `include/`; programs can use `#include "header_name.h"`.
Then commit and push as usual. No CMake edits or README updates are needed for
new standalone exercises.

Each top-level `.cpp` in `src/` is a complete program. When an exercise grows into a project
with several `.cpp` files sharing one `main()`, give that project its own folder and
explicit CMake target; those files should be built together.

This small learning repository deliberately discovers standalone exercises by filename.
For larger applications, explicit source lists give better control over what is built.

## Automatic checks

Every push and pull request configures and builds the exercises on Linux, macOS,
and Windows. The badge above shows the build status of `main`.
These checks verify compilation and linking; they do not verify interactive program behavior.

The repository does not require a separate progress report or manual exercise index.
Learning notes and the practice tracker are independent of the build checks.
