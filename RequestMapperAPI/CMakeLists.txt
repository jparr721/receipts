cmake_minimum_required(VERSION 3.8)
project(RequestMapper)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES requestMapper.cpp requestMapper.hpp)
add_executable(rm ${SOURCE_FILES})
