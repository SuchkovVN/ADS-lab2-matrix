cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Matrix)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
project(${PROJECT_NAME})

set(vector VectorMain)
set(vectorlib VectorLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)

add_subdirectory(Vector)
add_subdirectory(VectorLib)



