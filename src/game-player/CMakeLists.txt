add_library(game-player game-player.h game-player.cpp)

target_link_libraries(game-player fslazywindow ysclass)
target_include_directories(game-player PUBLIC .)

add_executable(game-player-test MACOSX_BUNDLE game-player-test.cpp)
target_link_libraries(game-player-test fslazywindow ysclass game-player)
target_include_directories(game-player-test PUBLIC .)


