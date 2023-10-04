cmake_minimum_required(VERSION 3.26)
project(linkstack_test C)

set(CMAKE_C_STANDARD 11)

add_executable(linkstack_test main.c
        linkstack.h
        linkstack.c)
