cmake_minimum_required(VERSION 3.26)
project(triangraph)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/grapph/include)
link_directories(lib)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(grapph STATIC include/grapph/src/Graph.cpp include/grapph/src/Homomorphism.cpp)

add_executable(coordinate_plane_test include/CoordinatePlane.h
        test/CoordinatePlaneTest.cpp)
target_link_libraries(coordinate_plane_test gtest gtest_main grapph)

add_executable(triangle_test include/Triangle.h src/Triangle.cpp
        test/TriangleTest.cpp)
target_link_libraries(triangle_test gtest gtest_main grapph)