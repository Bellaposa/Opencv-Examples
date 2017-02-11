project( HistogramEqualiz )

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( HistogramEqualiz main.cpp )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY “./Build/”)
target_link_libraries( HistogramEqualiz ${OpenCV_LIBS} )
