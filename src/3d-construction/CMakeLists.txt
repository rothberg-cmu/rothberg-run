add_executable(3d-construction MACOSX_BUNDLE main.cpp DrawingRoad.cpp ../map-generation/Road.cpp)
target_link_libraries(3d-construction fslazywindow ysclass)
