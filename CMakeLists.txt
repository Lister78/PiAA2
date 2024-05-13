cmake_minimum_required(VERSION 3.10)
project(GraphShortestPath)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB INC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h")

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")

add_executable(GraphShortestPath ${SRC_FILES} ${INC_FILES})

