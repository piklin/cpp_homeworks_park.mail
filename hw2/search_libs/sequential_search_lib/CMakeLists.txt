project(sequential_search)
cmake_minimum_required(VERSION 3.9)

add_library(${PROJECT_NAME}_lib STATIC src/lib_funcs.c ${COMMON_SRC}/for_searchers.c)
include_directories(include)