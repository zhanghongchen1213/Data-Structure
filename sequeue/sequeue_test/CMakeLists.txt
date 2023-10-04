cmake_minimum_required(VERSION 3.26)
project(sequeue_test C)

set(CMAKE_C_STANDARD 11)

add_executable(sequeue_test main.c
        sequeue.h
        sequeue.c)
