cmake_minimum_required(VERSION 3.17)
project(linked_list C)

set(CMAKE_C_STANDARD 11)

#add_library(linked_list SHARED library.c library.h)
#add_executable(linked_list library.c library.h lib_linked_list.c lib_linked_list.h)
add_executable(linked_list lib_linked_list.c lib_linked_list.h)