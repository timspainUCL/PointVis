add_executable(pointVisTest pointVisTest.cpp)

target_link_libraries(pointVisTest LINK_PUBLIC PointVis)
target_link_libraries(pointVisTest PRIVATE Catch2::Catch2)

add_test(NAME PointVisTest COMMAND PointVisTest)