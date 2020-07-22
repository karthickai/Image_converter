cmake_minimum_required(VERSION 3.16)
project(image_converter)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
set(OpenCV_DIR /opt/opencv/lib/cmake)
find_package(OpenCV REQUIRED )

add_executable(image_converter main.cpp)
target_link_libraries( image_converter ${OpenCV_LIBS} )