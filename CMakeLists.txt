cmake_minimum_required(VERSION 3.3)
project(cube)

set(gtest_force_shared_crt ON)

add_subdirectory(gtest)
add_library(cubeLib STATIC src/cube.cpp src/cube.h)
add_executable(cube src/main.cpp)

include_directories(gtest/include)
add_executable(cube_test test/cube_tests.cpp)
target_link_libraries(cube_test gtest gtest_main cubeLib)
target_link_libraries(cube cubeLib)
