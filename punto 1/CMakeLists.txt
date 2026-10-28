cmake_minimum_required(VERSION 3.16)
project(meetup CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(meetup
    meetup_test.cpp
    meetup.cpp
    meetup.h
)

target_link_libraries(meetup PRIVATE GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME meetup_tests COMMAND meetup)
