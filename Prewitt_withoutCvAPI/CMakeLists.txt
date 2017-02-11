project( Prewitt )

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Prewitt main.cpp )
target_link_libraries( Prewitt ${OpenCV_LIBS} )