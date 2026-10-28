cmake_minimum_required(VERSION 3.16)
project(clock_exercise CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(clock_test
    clock_test.cpp
    clock.cpp
    clock.h
)

target_link_libraries(clock_test PRIVATE GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME clock_tests COMMAND clock_test)
