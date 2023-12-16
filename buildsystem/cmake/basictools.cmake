##########
# CMAKE Helper functions to make the code easier to read and more structured
#


function( bs_set_cmake_prefix_path )
    set(CMAKE_PREFIX_QT6 FILEPATH "/home/stuv/Qt/6.6.1/gcc_64/lib/cmake/Qt6")
    set(CMAKE_PREFIX_PYTHON FILEPATH "/home/stuv/projects/build/python3.13")
    set(QT6_RPATH FILEPATH "/home/stuv/Qt/6.6.1/gcc_64/lib")
endfunction()

## SETUP CMAKE DEBUG/REKEASE OPTIONS
#
#
function( bs_set_build_type )
  #default to DEBUG
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
  endif()

  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  endif()

  if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-Wall")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
  endif()
endfunction()

#bs_add_library
#add_subdirectory()
