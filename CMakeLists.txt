cmake_minimum_required(VERSION 3.10)

project(secondAssignment)

# LIBRARIES SECTION
add_library(linalglib STATIC src/MatrixBase.cpp) # STATIC
target_include_directories(linalglib PRIVATE include)


# TESTS SECTION
# Basically makes CMake read the CMakeLists.txt file contained in tests
add_subdirectory(tests)