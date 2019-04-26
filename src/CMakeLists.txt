
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(public/src)

add_subdirectory(3d-construction)
add_subdirectory(game-player)
add_subdirectory(map-generation)
add_subdirectory(camera)
add_subdirectory(coins)
add_subdirectory(obstacle)