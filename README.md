# Data Structures in C++ (Educational)

This repo contains simple, well-documented implementations of common data structures in modern C++:
- LinkedList (template-based, unique_ptr)
- Stack, Queue (wrappers)
- Binary Search Tree

## Build & Run
See CMakeLists.txt or compile directly:
g++ -std=c++17 src/main_tests.cpp -o run_tests
./run_tests

## Design goals
- Educational, readable implementations
- Avoid raw new/delete (use smart pointers)
- Simple test harness (assert)
