add_library(
    Obstacle
    Obstacle.cpp
    Obstacle.h
)

target_link_libraries(Obstacle Map)

target_link_directories(Obstacle PUBLIC .)