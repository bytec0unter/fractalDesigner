cmake_minimum_required(VERSION 3.28)
project(bsApplication VERSION 0.0.1 LANGUAGES CXX)

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/buildsytem/cmake)
include("basictools")

## SETUP VARIABLES so that cmake can find the packages
#
bs_set_cmake_prefix_path()

bs_set_build_type()

if(NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)
endif()


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
    REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets Svg
)

# find python library located at /home/stuv/build/python3.13/lib/libpython3.13.so
find_package(
  Python3 3.13.0
  REQUIRED COMPONENTS Interpreter Development
)

qt6_standard_project_setup()



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

set(MOD_QT6 Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets Qt6::Svg)
set(PYTHON_LIBRARIES Python3::Python3 Python3_LIBARY_DIRS)


# qt6 set include directories and link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE MOD_QT6 Python3_LIBARY_DIRS)

target_include_directories(${PROJECT_NAME} PRIVATE MOD_QT6 Python3_INCLUDE_DIRS
)

target_link_libraries(${PROJECT_NAME} PRIVATE MOD_QT6 Python3::Python ${CMAKE_DL_LIBS})

# python set include directories and link libraries
target_include_directories(${PROJECT_NAME} PRIVATE Python3_INCLUDE_DIRS)
target_link_directories(${PROJECT_NAME} PRIVATE Python3_LIBARY_DIRS)


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
