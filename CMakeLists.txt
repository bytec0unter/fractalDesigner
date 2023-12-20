cmake_minimum_required(VERSION 3.28)
project(bsApplication VERSION 0.0.1 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/buildsystem/cmake)
include("basictools")


## SETUP VARIABLES so that cmake can find the packages
#
#TODO Make CMAKE_PREFIX_PATH work in this CMakelists.txt file!
#bs_set_cmake_prefix_path()

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}"
        " CMAKE_PREFIX_QT6: ${CMAKE_PREFIX_QT6}"
        " CMAKE_PREFIX_PYTHON3: ${CMAKE_PREFIX_PYTHON3}"
        " QT6_RPATH: ${QT6_RPATH}")

#set(CMAKE_PREFIX_QT6 "/home/stuv/Qt/6.6.1/gcc_64/lib/cmake/Qt6")
#set(CMAKE_PREFIX_PYTHON3 "/home/stuv/projects/build/python3.13")
#set(QT6_RPATH "/home/stuv/Qt/6.6.1/gcc_64/lib")
#list(APPEND CMAKE_PREFIX_PATH ${CMAKE_PREFIX_QT6} ${CMAKE_PREFIX_PYTHON3})



bs_set_build_type()

bs_set_output_path()

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER:FILEPATH=/usr/bin/gcc)
set(CMAKE_CXX_COMPILER:FILEPATH=/usr/bin/g++)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_RELEASE "-O3")

## SETUP PACKAGES
#
#
find_package(
    Qt6 6.6.1
    COMPONENTS Core Quick Gui Widgets Svg OpenGLWidgets REQUIRED
)
qt6_standard_project_setup()

# find python library located at /home/stuv/build/python3.13/lib/libpython3.13.so
find_package(
  Python3 3.13.0
  REQUIRED COMPONENTS Interpreter Development
)




file(GLOB_RECURSE SOURCES
  src/*.cpp
  src/*.h
)


add_executable(${PROJECT_NAME} ${SOURCES})





set(QT_DEBUG_PLUGINS ON)

#set(SKIP_BUILD_RPATH true)
set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "${QT6_RPATH}")

set_target_properties(${PROJECT_NAME} PROPERTIES RELEASE_OUTPUT_NAME bsFractalDesigner_release)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_OUTPUT_NAME bsFractalDesigner_debug)

set(MOD_QT6 Qt6::Core Qt6::Gui Qt6::Widgets  Qt6::OpenGLWidgets Qt6::Svg)
set(PYTHON_LIBRARIES Python3::Python Python3_LIBARY_DIRS)


# qt6 set include directories and link libraries
target_include_directories(${PROJECT_NAME} PRIVATE Python3::Python Python3_INCLUDE_DIRS)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MOD_QT6} ${PYTHON_LIBRARIES} ${CMAKE_DL_LIBS})


set_target_properties(${PROJECT_NAME} PROPERTIES RELEASE_OUTPUT_NAME ${PROJECT_NAME}_release)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_OUTPUT_NAME ${PROJECT_NAME}_debug)




install(
  TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/out
)



install(
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/out
)
