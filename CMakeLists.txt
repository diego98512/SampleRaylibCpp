cmake_minimum_required(VERSION 3.15)
project(SampleRaylib)

set(CMAKE_CXX_STANDARD 11)
set(INCLUDE_DIRECTORIES ./)

add_executable(SampleRaylib src/main.cpp)

target_link_libraries(${PROJECT_NAME} raylib)