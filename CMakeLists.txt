cmake_minimum_required(VERSION 3.2)
project(CppThreadTest)

# In using std::thread, add -pthread
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(SOURCE_FILES main.cpp)
add_executable(CppThreadTest ${SOURCE_FILES})