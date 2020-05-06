cmake_minimum_required(VERSION 3.10)

project(secondAssignment)

# Standard set to 17 to have mandatory RVO
set(CMAKE_CXX_STANDARD 17)


# LIBRARIES SECTION
add_library(linalglib STATIC
        src/MatrixBase.cpp
        src/Vector.cpp
        src/Matrix.cpp) # STATIC
target_include_directories(linalglib PRIVATE include/linalglib)


# TESTS SECTION
# Basically makes CMake read the CMakeLists.txt file contained in tests
add_subdirectory(tests)