cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0015 NEW)

project(Grayscale)
find_package(OpenCV REQUIRED)

#include_directories(${MyProject_SOURCE_DIR}/examples/grayscale/include)

# I want to use S11622 as a library in Grayscale project.
include_directories(../../lib/include)
link_directories(../../lib/src)

add_executable(grayscale grayscale_16.cpp)

target_link_libraries(grayscale S11622)
target_link_libraries(grayscale ${OpenCV_LIBS})

#https://stackoverflow.com/questions/8304190/cmake-with-include-and-source-paths-basic-setup