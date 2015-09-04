cmake_minimum_required(VERSION 3.3)
project(cube)

set(gtest_force_shared_crt ON)

add_subdirectory(gtest)
add_executable(cube src/cube.cpp src/cube.h)

include_directories(gtest/include)
add_executable(cube_test test/cube_tests.cpp)
target_link_libraries(cube_test gtest gtest_main)