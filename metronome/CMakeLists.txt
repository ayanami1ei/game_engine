cmake_minimum_required(VERSION 3.18)
project(Metronome CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(Metronome SHARED ${SRC_FILES})
target_include_directories(Metronome PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Ensure literal -lpthread is appended to the final link command for Test
if (TARGET Test)
    target_link_options(Test PRIVATE "-lpthread")
endif()