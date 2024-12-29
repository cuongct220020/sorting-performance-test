cmake_minimum_required(VERSION 3.10...3.21)
project(test-cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(test-cpp src/main.cpp 
                        src/sorting-algo.cpp 
                        src/file-io.cpp
                        src/exec-time.cpp)

include(CTest)
enable_testing()

