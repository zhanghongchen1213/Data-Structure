cmake_minimum_required(VERSION 3.26)
project(linklist_test C)

set(CMAKE_C_STANDARD 11)

add_executable(linklist_test main.c
        linklist.h
        linklist.c)
