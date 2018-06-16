cmake_minimum_required(VERSION 3.10)
project(graph_algo_api)

set(CMAKE_CXX_STANDARD 11)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#include_directories(src)

add_executable(graph_algo_tests
        src/TestRingIndex.cpp)
target_link_libraries(graph_algo_tests ${GTEST_LIBRARIES} pthread)
