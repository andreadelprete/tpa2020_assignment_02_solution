cmake_minimum_required(VERSION 3.10)

project(secondAssignment)

# Standard set to 17 to have mandatory RVO
set(CMAKE_CXX_STANDARD 17)


# LIBRARIES SECTION
add_library(liblinalg STATIC
        src/MatrixBase.cpp
        src/Vector.cpp
        src/Matrix.cpp) # STATIC
target_include_directories(liblinalg PRIVATE include)

add_library(libsimcon STATIC
        src/Controller.cpp
        src/Simulator.cpp)
target_include_directories(libsimcon PRIVATE include)
target_link_libraries(libsimcon liblinalg)


# Basic main section
add_executable(mainEntry main.cpp)
target_sources(mainEntry PRIVATE src/ClosedLoop.cpp)
target_include_directories(mainEntry PRIVATE include)
target_link_libraries(mainEntry
        liblinalg
        libsimcon)

# TESTS SECTION
# Basically makes CMake read the CMakeLists.txt file contained in tests
add_subdirectory(tests)