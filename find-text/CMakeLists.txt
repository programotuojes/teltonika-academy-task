cmake_minimum_required(VERSION 3.17)
project(find_text C)

set(CMAKE_C_STANDARD 11)

add_executable(find_text main.c util.c main.h)