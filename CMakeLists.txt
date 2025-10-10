cmake_minimum_required(VERSION 3.16)

project(Abstract2D LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_ANDROID "Build for android" OFF)
option(BUILD_SHARED_LIBS "Build as shared library" OFF)

add_subdirectory(engine)
add_subdirectory(game)
