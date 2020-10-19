cmake_minimum_required(VERSION 3.10)
PROJECT(hello)
add_definitions(-DCELLO_NGC)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
include_directories(../common/include)
set(CMAKE_BUILD_TYPE "Debug")

include_directories(./include)
link_directories(./)

link_libraries(Cello)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

AUX_SOURCE_DIRECTORY(./src cello_src)


ADD_EXECUTABLE(hello ./main.c ${cello_src})