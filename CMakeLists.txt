project(hw1)
cmake_minimum_required(VERSION 3.17)

add_executable(run src/main.c src/r_w_computets.c)
target_include_directories(run PUBLIC include)
