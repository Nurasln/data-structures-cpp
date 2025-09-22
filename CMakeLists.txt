cmake_minimum_required(VERSION 3.10)
project(data_structures_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Header folders
include_directories(${CMAKE_SOURCE_DIR}/include)

#Test folders
add_executable(run_tests tests/linked_list_test.cpp)
add_executable(run_stack_test tests/stack_test.cpp)
add_executable(run_queue_test tests/circular_queue.h)
add_executable(run_bst_test tests/bst_test.cpp)
