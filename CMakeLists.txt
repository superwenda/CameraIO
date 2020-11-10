cmake_minimum_required(VERSION 3.17)
project(CameraIO)

add_definitions(/MT)
set(CMAKE_MFC_FLAG 1)

set(OpenCV_DIR "D:/lib/opencv/build")
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(cameraio)

add_subdirectory(test)
add_subdirectory(cameraio)