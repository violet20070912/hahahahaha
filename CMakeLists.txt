cmake_minimum_required(VERSION 3.16)

project(reprojection LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(reprojection_app
    src/main.cpp
src/reprojection.cpp
)

target_include_directories(reprojection_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
