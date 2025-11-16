cmake_minimum_required(VERSION 3.16)
project(playground CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

# Add your executable
add_executable(main src/main.cpp)