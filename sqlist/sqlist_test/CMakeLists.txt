cmake_minimum_required(VERSION 3.26)
project(sqlist_test C)

set(CMAKE_C_STANDARD 11)

add_executable(sqlist_test main.c
        sqlist.h
        sqlist.c
)
