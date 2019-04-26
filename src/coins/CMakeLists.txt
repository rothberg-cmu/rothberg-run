add_library(Coins Coins.cpp Coins.h)

target_link_libraries(Coins ysclass Map)
target_include_directories(Coins PUBLIC .)
