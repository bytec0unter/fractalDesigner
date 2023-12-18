##########
# CMAKE Helper functions to make the code easier to read and more structured
#


function(bs_set_cmake_prefix_path)
#  block(PROPAGATE CMAKE_PREFIX_PYTHON3 CMAKE_PREFIX_QT6 QT6_RPATH CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PYTHON3 "/home/stuv/projects/build/python3.13" CACHE INTERNAL)
    set(CMAKE_PREFIX_QT6 "/home/stuv/Qt/6.6.1/gcc_64/lib/cmake/Qt6" CACHE INTERNAL)
    set(QT6_RPATH "/home/stuv/Qt/6.6.1/gcc_64/lib" CACHE INTERNAL)
    set(CMAKE_REFIX_PATH ${CMAKE_PREFIX_QT6} ${CMAKE_PREFIX_PYTHON3} CACHE INTERNAL)
#  endblock()

endfunction()

## SETUP CMAKE DEBUG/REKEASE OPTIONS
#
#
function(bs_set_build_type)
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


function(bs_set_output_path)
  if(NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)
  endif()
endfunction()




#bs_add_library
#add_subdirectory()
