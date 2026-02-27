cmake_minimum_required(VERSION 3.18)
project(MinimalRayTracer CUDA CXX)

set(CMAKE_CXX_STANDARD 17)
find_package(CUDA REQUIRED)

include_directories(include)

add_executable(MinimalRayTracer src/main.cpp src/render.cu)
set_target_properties(MinimalRayTracer PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON)