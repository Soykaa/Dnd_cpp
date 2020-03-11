cmake_minimum_required(VERSION 3.12)
project(DND_CPP)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra")
include_directories(src)

set(TRAVIS_TEST_SOURCES src/main_travis.cpp src/travis/travis.cpp)

add_executable(travis_test ${TRAVIS_TEST_SOURCES})
