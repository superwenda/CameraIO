cmake_minimum_required(VERSION 3.11)

add_executable(GrabImage "GrabImage.cpp")
target_link_libraries(GrabImage ${OpenCV_LIBS} camera)

add_executable(testapi "testapi.cpp")