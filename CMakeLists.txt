cmake_minimum_required(VERSION 3.14)
project(PointVis)

#FetchContent_MakeAvailable(Catch2)

find_package(Catch2 REQUIRED)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
