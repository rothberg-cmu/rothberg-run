add_library(Camera
    Camera.h
    Camera.cpp)

add_executable(CameraTest
    CameraTest.cpp
    Camera.h
    Camera.cpp)

target_link_libraries(Camera ysclass game-player) 
target_link_libraries(CameraTest ysclass fslazywindow game-player) 
target_include_directories(Camera PUBLIC .)