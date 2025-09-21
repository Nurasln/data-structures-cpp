cmake_minimum_required(VERSION 3.10)
project(data_structures_cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(run_tests src/main_tests.cpp)
