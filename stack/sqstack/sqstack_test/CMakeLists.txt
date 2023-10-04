cmake_minimum_required(VERSION 3.26)
project(sqstack_test C)

set(CMAKE_C_STANDARD 11)

add_executable(sqstack_test main.c
        sqstack.c
        sqstack.h)
