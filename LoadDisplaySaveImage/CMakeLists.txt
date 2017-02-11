project( LoadDisplaySaveImage )

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( LoadDisplaySaveImage main.cpp )
target_link_libraries( LoadDisplaySaveImage ${OpenCV_LIBS} )