add_library(
    Obstacle
    Obstacle.cpp
    Obstacle.h
    binstl.cpp
    binstl.h
)

target_link_libraries(Obstacle Map fslazywindow)

target_link_directories(Obstacle PUBLIC .)