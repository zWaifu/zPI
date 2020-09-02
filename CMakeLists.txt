cmake_minimum_required(VERSION 3.5)

# zWaifu Plugin Infrastructure
project(zPI LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Quick REQUIRED)
find_package(spdlog CONFIG REQUIRED)


set(zPI_HDR
    IzWaifuEngine.h
    IzWaifuFunctionPlugin.h
    zWaifuStageManager.h
    )

list(TRANSFORM zPI_HDR PREPEND "include/")

include_directories("include")

add_library(zPI INTERFACE)
target_sources(zPI INTERFACE ${zPI_HDR})

target_include_directories(zPI INTERFACE "include")

add_library(zPI_dummy STATIC ${zPI_HDR})
target_include_directories(zPI_dummy PRIVATE "include")
target_link_libraries(zPI_dummy PRIVATE Qt5::Widgets)
target_link_libraries(zPI_dummy PRIVATE spdlog::spdlog)

#target_compile_definitions(zPI PRIVATE ZPI_LIBRARY)
