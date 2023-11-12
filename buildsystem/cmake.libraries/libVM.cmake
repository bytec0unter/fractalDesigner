#first build libary

set(
    LIBWM_SOURCE_FILES 
    ${CMAKE_SOURCE_DIR}/src/bsVM.h
    ${CMAKE_SOURCE_DIR}/src/bsVM.cpp

))

add_library(
    libWM STATIC PRIVATE 
    ${LIBWM_SOURCE_FILES})