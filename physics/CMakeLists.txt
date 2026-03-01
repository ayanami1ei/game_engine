cmake_minimum_required(VERSION 3.18)
project(Physics CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(
    "../math"
    "${CMAKE_BINARY_DIR}/math"
)
include_directories("../math/include")

add_subdirectory(
    "../metronome"
    "${CMAKE_BINARY_DIR}/metronome"
)
include_directories("../metronome/include")

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE TEST_FILES
    "${PROJECT_SOURCE_DIR}/test/*.cpp"
)

add_library(Physics SHARED ${SRC_FILES})
add_executable(Test ${TEST_FILES})

# Find pthreads and link where needed
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(Physics PUBLIC Math Metronome Threads::Threads)
target_link_libraries(Test PRIVATE Physics Threads::Threads)

# Ensure literal -lpthread is appended to the final link command for Test
if (TARGET Test)
    target_link_options(Test PRIVATE "-lpthread")
endif()