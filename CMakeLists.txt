# Minimum Requrement of CMake
cmake_minimum_required (VERSION 2.6)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

# Set project name
project (Load-Settings)

# Find boost library
#set(Boost_USE_STATIC_LIBS ON) 
#set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON) 
FIND_PACKAGE(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(main main.cpp)

TARGET_LINK_LIBRARIES( main ${Boost_LIBRARIES} )