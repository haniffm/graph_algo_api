cmake_minimum_required(VERSION 3.10)
project(graph_algo_api)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(graph_algo_api
        src/graph_algo_api.cpp
        src/Point.h
        src/RingIndex.h
        src/TestPoint.h)
