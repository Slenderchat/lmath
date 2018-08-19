cmake_minimum_required(VERSION 3.12)
project(lmath)

set(CMAKE_CXX_STANDARD 17)

add_library(lmath SHARED lmath.cpp lmath.h main.cpp)
add_executable(main main.cpp)
target_link_libraries(main lmath)