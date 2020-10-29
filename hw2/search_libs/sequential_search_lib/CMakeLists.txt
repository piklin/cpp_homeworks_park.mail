project(sequential_search)
cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic -coverage")

add_library(${PROJECT_NAME}_lib STATIC src/lib_funcs.c ${COMMON_SRC}/for_searchers.c)
include_directories(include)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic -coverage")

add_executable(sequential_lib_tests tests/tests.cpp)
target_include_directories(sequential_lib_tests PRIVATE ${PROJECT_NAME}_lib)
find_package(GTest REQUIRED)
target_include_directories(sequential_lib_tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(sequential_lib_tests ${GTEST_LIBRARIES} pthread ${PROJECT_NAME}_lib)