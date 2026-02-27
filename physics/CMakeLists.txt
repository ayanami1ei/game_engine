cmake_minimum_required(VERSION 3.18)
project(PHYSICS CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(PHYSICS STATIC ${SRC_FILES})

target_link_libraries(PHYSICS PRIVATE
    "/home/ayanami/game engine/math/build/libMath.a"
)