cmake_minimum_required(VERSION 3.29)
project(OS_lab1 C)

set(CMAKE_C_STANDARD 23)

include_directories(include)

file(GLOB_RECURSE SOURCES "./*.c")
file(GLOB_RECURSE HEADERS "include/*.h")

add_executable(OS_lab1 ${SOURCES} ${HEADERS})
