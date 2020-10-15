project(hw1)
cmake_minimum_required(VERSION 3.9)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)


add_executable(run src/main.c src/r_w_computets.c)
target_include_directories(run PUBLIC include)


add_executable(tests tests/tests.cpp src/r_w_computets.c)
find_package(GTest REQUIRED)
target_include_directories(tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(tests PUBLIC ${GTEST_LIBRARIES})
target_include_directories(tests PUBLIC include)
