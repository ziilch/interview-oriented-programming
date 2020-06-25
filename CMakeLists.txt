#cmake_minimum_required(VERSION 3.13)
#project(interview-oriented-programming CXX)
#set_target_properties(interview-coding PROPERTIES LINKER_LANGUAGE CXX)
#set(CMAKE_CXX_STANDARD 11)
#
#include_directories(.)
#
#add_executable(interview-oriented-programming
#        includes/BaseInclude.h
#        src/SortMethod.hpp src/BinarySearch.hpp src/DpMethod.hpp)

cmake_minimum_required(VERSION 3.5)

project(interview-programming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ./ main.cpp src/)

add_executable(interview-programming ${SOURCE_FILES})
