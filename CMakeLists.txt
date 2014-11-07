# Minimum Requrement of CMake
cmake_minimum_required (VERSION 2.6)

ADD_DEFINITIONS(-std=c++11)

# Set project name
project (Load-Settings)

# Find boost library
FIND_PACKAGE(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(main main.cpp)

