cmake_minimum_required(VERSION 3.10...3.21)
project(sorting_performance_test_cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(sorting_performance_test_cpp 
    src/main.cpp 
    src/sorting-algo.cpp 
    src/file-io.cpp
    src/exec-time.cpp
)