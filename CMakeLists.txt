############################################################################
# Actual project.

cmake_minimum_required(VERSION 3.12)
project(DND_CPP)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra")
include_directories(include)

set(TRAVIS_SOURCES src/travis/travis.cpp)
set(TRAVIS_MAIN src/travis/main_travis.cpp)

add_executable(travis ${TRAVIS_SOURCES} ${TRAVIS_MAIN})

############################################################################
# Google Test setup.

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

############################################################################
# Unit tests.
file(GLOB_RECURSE UNIT_TEST_SOURCES "tests/*_test.cpp")
add_executable(run_tests ${UNIT_TEST_SOURCES} ${TRAVIS_SOURCES})
target_link_libraries(run_tests gtest_main)
