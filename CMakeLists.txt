cmake_minimum_required(VERSION 3.20)
project(RPGgame)

set(CMAKE_CXX_STANDARD 23)

set(SFML_INCLUDE_DIR "lib/SFML/include")
set(SFML_LIBRARY_DIR "lib/SFML/lib")
set(SFML_DIR "lib/SFML/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

set(SOURCE_FILES main.cpp)
include_directories(${SFML_INCLUDE_DIR})
add_executable(RPGgame main.cpp)
target_link_libraries (RPGgame sfml-graphics sfml-window sfml-system sfml-audio)
