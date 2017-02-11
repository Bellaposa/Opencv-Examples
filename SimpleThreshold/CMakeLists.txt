project( SimpleThreshold )

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( SimpleThreshold main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY “./Build”)
target_link_libraries( SimpleThreshold ${OpenCV_LIBS} )
