cmake_minimum_required(VERSION 3.14)
project(PointVis)

#FetchContent_MakeAvailable(Catch2)

find_package(Catch2 REQUIRED)
enable_testing()

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
#  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2)

if (NOT VTK_FOUND)
  message("Skipping OctExample: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()


add_subdirectory(src)
add_subdirectory(test)
