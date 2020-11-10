cmake_minimum_required(VERSION 3.11)


find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

set(MICROVIEW_DIR "D:/lib/Microview/SDKAPI")
find_package(MICROVIEW)
include_directories(${MICROVIEW_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR})

add_library(camera microview.cpp)
target_link_libraries(camera ${OpenCV_LIBS} ${MICROVIEW_LIBS})

