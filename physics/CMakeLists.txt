cmake_minimum_required(VERSION 3.18)
project(Physics CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(
    "/home/ayanami/game engine/math"
    "${CMAKE_BINARY_DIR}/math"
)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories("/home/ayanami/game engine/math/include")
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(Physics STATIC ${SRC_FILES})

target_link_libraries(Physics PRIVATE
    "/home/ayanami/game engine/math/build/libMath.a"
)