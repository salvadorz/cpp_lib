#******************************************************************************
#*Copyright (C) 2023 by Salvador Z                                            *
#*                                                                            *
#*****************************************************************************/
#*
#*@author Salvador Z
#*@brief CMakeLists file to create a CMake project
#*
cmake_minimum_required(VERSION 3.0.0)
project(CPP_LIBs
  VERSION 0.1.0
  DESCRIPTION "Project for custom CPP libraries and utilities"
  LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

### Build Options ###
option(ENABLE_COVERAGE "Enable coverage reporting"              OFF)

### General Configuration ###

set_property(GLOBAL PROPERTY C_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD 17)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

### Enabling testig for current directory and below
#enable_testing()

### Compiler Flags Configuration ###

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

### Enabling CMAKE Modules
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

##########################
# Enable Static Analysis #
##########################
#include(analysis/code-format)


### General Project Structure ###

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Create an output dir in CMAKE_BINARY_DIR
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE})

# Use this directory to test and emulate a filesystem env
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/artifacts)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include
        DESTINATION ${CMAKE_INSTALL_PREFIX})

### Project Source Tree ###
add_subdirectory("lib")