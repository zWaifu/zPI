cmake_minimum_required(VERSION 3.5)

# zWaifu Plugin Infrastructure
project(zPI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)

set(zPI_HDR
    IzWaifuEngine.h
    IzWaifuFunctionPlugin.h
    )

list(TRANSFORM zPI_HDR PREPEND "include/")

add_library(zPI STATIC
  ${zPI_HDR}
)

target_include_directories(zPI PRIVATE "include")

target_link_libraries(zPI PRIVATE Qt5::Widgets)

target_compile_definitions(zPI PRIVATE ZPI_LIBRARY)
