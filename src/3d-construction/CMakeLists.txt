add_executable(3d-construction MACOSX_BUNDLE main.cpp)
add_executable(DrawingRoad MACOSX_BUNDLE DrawingRoadTest.cpp DrawingRoad.cpp ../map-generation/Road.cpp)
target_link_libraries(3d-construction fslazywindow ysclass)
target_link_libraries(DrawingRoad fslazywindow ysclass)
