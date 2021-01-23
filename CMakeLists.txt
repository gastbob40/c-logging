cmake_minimum_required(VERSION 3.17)
project(c_logger C)

set(CMAKE_C_STANDARD 99)

add_executable(c_logger main.c lib/logger.c)