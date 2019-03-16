add_library(Camera
    Camera.h
    Camera.cpp)

target_link_libraries(Camera ysclass)
target_include_directories(Camera PUBLIC .)