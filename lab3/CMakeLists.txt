cmake_minimum_required(VERSION 3.21)
project(lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab3 task2/main.c task2/task2_lib.c task2/time.c)
