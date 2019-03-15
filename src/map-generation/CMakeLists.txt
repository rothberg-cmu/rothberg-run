add_library(Map
    Map.h
    Map.cpp)
add_library(Road
    Road.h
    Road.cpp)

target_link_libraries(Map ysclass)
target_include_directories(Map PUBLIC .) 

target_link_libraries(Road ysclass)
target_include_directories(Road PUBLIC .) 

add_executable(MapTest MapTest.cpp)
target_link_libraries(MapTest Map Road)