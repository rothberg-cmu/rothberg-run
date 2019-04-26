add_library(Coins Coins.cpp Coins.h binstl.cpp binstl.h)

target_link_libraries(Coins ysclass Map fslazywindow)
target_include_directories(Coins PUBLIC .)
