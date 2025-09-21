cmake_minimum_required(VERSION 3.10)
project(data_structures_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Header folders
include_directories(${CMAKE_SOURCE_DIR}/include)

#Test folders
add_executable(run_tests tests/linked_list_test.cpp)
