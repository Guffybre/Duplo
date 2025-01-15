cmake_minimum_required(VERSION 3.15.5)
project(duplo)
file(GLOB SOURCES src/*.cpp)

option(EXPORT_COMPILE_COMMANDS "Export compile_commands.json" OFF)

set(DUPLO_VERSION "\"v1.0.1\"" CACHE STRING "Duplo version")
if(EXPORT_COMPILE_COMMANDS)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()


if(MSVC)
else()
    add_compile_options(-O3 -Wall -Werror -std=c++17)
    add_compile_definitions(DUPLO_VERSION=${DUPLO_VERSION})
endif()
add_executable(duplo ${SOURCES})
