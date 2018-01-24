cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(zeus VERSION 0.3.17 LANGUAGES CXX)

#Ensure we are in the correct build directory
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "In source builds not allowed. Please make a new directory (called a build direcotry) and run CMake from there\n")
endif()

set(CMAKE_CXX_STANDARD 11)

#Add in the extra cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)

find_package(CURL REQUIRED)

enable_testing()

add_subdirectory(Theia)
add_subdirectory(app)
