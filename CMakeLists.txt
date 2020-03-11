cmake_minimum_required(VERSION 3.15)
project(DND_CPP)
set(CMAKE_CXX_STANDARD 20)
include_directories(src)

set(TRAVIS_TEST_SOURCES src/main_travis.cpp src/travis/travis.cpp)

add_executable(travis_test ${TRAVIS_TEST_SOURCES})
