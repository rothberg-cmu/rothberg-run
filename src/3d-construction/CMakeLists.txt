add_executable(3d-construction MACOSX_BUNDLE main.cpp)
target_link_libraries(3d-construction fslazywindow ysclass game-player draw-player)

add_library(draw-player drawPlayer.h drawPlayer.cpp)
target_link_libraries(draw-player ysclass fslazywindow game-player)
target_include_directories(draw-player PUBLIC .)