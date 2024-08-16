cmake_minimum_required(VERSION 3.10)

# Project name and version
project(SortingAlgorithmsComparison VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable all warnings
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Function to recursively collect all source files in a directory
function(collect_sources DIR OUT_VAR)
    file(GLOB_RECURSE new_sources ${DIR}/*.cpp)
    set(all_sources ${${OUT_VAR}} ${new_sources})
    set(${OUT_VAR} ${all_sources} PARENT_SCOPE)
endfunction()

# Collect source files
collect_sources(${PROJECT_SOURCE_DIR}/Algorithms ALGORITHM_SOURCES)
collect_sources(${PROJECT_SOURCE_DIR}/Tools TOOL_SOURCES)
collect_sources("${PROJECT_SOURCE_DIR}/Test Data" TEST_DATA_SOURCES)

# Combine all source files into a single list
set(SOURCES ${ALGORITHM_SOURCES} ${TOOL_SOURCES} ${TEST_DATA_SOURCES} ${PROJECT_SOURCE_DIR}/main.cpp)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/Algorithms)
include_directories(${PROJECT_SOURCE_DIR}/Tools)
include_directories("${PROJECT_SOURCE_DIR}/Test Data")

# Create a single executable that includes all algorithms and tools
add_executable(SortingAlgorithmsComparison ${SOURCES})

# Print summary of the project
message(STATUS "CMake project for SortingAlgorithmsComparison")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Total Source Files: ${SOURCES}")

