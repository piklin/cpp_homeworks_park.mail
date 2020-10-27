project(parallel_search)
cmake_minimum_required(VERSION 3.17)

add_library(${PROJECT_NAME}_lib SHARED src/lib_funcs.c ${COMMON_SRC}/for_searchers.c)
include_directories(include)