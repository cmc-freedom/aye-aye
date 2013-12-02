cmake_minimum_required(VERSION 2.8)

project(aye-aye)

include_directories(./) # Access to headers from subdirectories

add_library(wide_system STATIC wide_system.c)

add_library(compilation STATIC compilation.c)
target_link_libraries(compilation wide_system)

add_subdirectory(tests)

