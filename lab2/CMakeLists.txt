cmake_minimum_required(VERSION 3.21)
project(lab2 C)

set(CMAKE_C_STANDARD 11)
include_directories(task3)
add_executable(SysOpy
        task3/main.c task3/task3_dir.c task3/task3_dir.h task3/task3_nftw.h task3/task3_nftw.c)
