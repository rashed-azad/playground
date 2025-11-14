cmake_minimum_required(VERSION 3.16)
project(playground CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake where to find your locally installed msquic
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/install")

# Find msquic package
find_package(msquic REQUIRED)

# Add your executable
add_executable(main src/main.cpp)

# Link msquic automatically
target_link_libraries(main PRIVATE msquic::msquic)