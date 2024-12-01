cmake_minimum_required(VERSION 3.26)
project(task_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(${CMAKE_PROJECT_NAME}_run main.cpp)

set(CMAKE_CXX_FLAGS "-g")

include_directories(src)
add_subdirectory(src)

add_subdirectory(Tests)

target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib)