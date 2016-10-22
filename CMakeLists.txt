cmake_minimum_required(VERSION 3.6)
project(AtomicGames)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(AtomicGames ${SOURCE_FILES})