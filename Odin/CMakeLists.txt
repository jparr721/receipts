cmake_minimum_required(VERSION 3.8)
project(RequestMapper)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES requestMapper.cpp requestMapper.hpp)
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
add_executable(rm ${SOURCE_FILES})
include_directories(${CURL_INCLUDE_DIR})

target_link_libraries(rm ${CURL_LIBRARIES})
