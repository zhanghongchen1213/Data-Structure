cmake_minimum_required(VERSION 3.26)
project(linkqueuetest C)

set(CMAKE_C_STANDARD 11)

add_executable(linkqueuetest main.c
        linkqueue.h
        linkqueue.c)
