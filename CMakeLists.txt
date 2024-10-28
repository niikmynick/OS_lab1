cmake_minimum_required(VERSION 3.29)
project(OS_lab1 C)

set(CMAKE_C_STANDARD 11)

# without optimization
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(OS_lab1 main.c ${SOURCES} ${HEADERS})
