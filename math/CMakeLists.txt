cmake_minimum_required(VERSION 3.18)
project(Math CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(Math SHARED ${SRC_FILES})
target_include_directories(Math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")