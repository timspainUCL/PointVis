add_library(PointVis PointVis.cpp)
target_include_directories(PointVis PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(OctExample MACOSX_BUNDLE octExample.cpp)
target_link_libraries(OctExample PRIVATE ${VTK_LIBRARIES})
# vtk_module_autoinit is needed
vtk_module_autoinit(
	TARGETS OctExample
    MODULES ${VTK_LIBRARIES}
	)

# include all components
add_executable(PointsExample MACOSX_BUNDLE PointsExample.cpp )
target_link_libraries(PointsExample PRIVATE ${VTK_LIBRARIES})
# vtk_module_autoinit is needed
vtk_module_autoinit(
    TARGETS PointsExample
    MODULES ${VTK_LIBRARIES}
    )
	