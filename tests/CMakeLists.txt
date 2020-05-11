# Sources that contain the tests
add_executable(catch2Test catch2Main.cpp) # Just this one contains BOOST_TEST_MAIN
target_include_directories(catch2Test PRIVATE
        ../include)
target_sources(catch2Test PRIVATE
        linalgTestsMat.cpp
        linAlgMatBaseTests.cpp
        linAlgVecTests.cpp
        simconTests.cpp
        ../src/ClosedLoop.cpp)

# Libraries used in the tests
target_link_libraries(catch2Test
        liblinalg
        libsimcon)