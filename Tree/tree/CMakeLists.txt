cmake_minimum_required(VERSION 3.26)
project(tree C)

set(CMAKE_C_STANDARD 11)

add_executable(tree main.c
        tree.c
        tree.h
        linkqueue.h
        linkqueue.c)
