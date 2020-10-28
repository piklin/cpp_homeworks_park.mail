set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wpedantic")


add_executable(sequential_search_example src/main.c)
target_include_directories(sequential_search_example PRIVATE ${ROOT_CMAKE_DIR}/search_libs/include)
target_link_libraries(sequential_search_example PRIVATE sequential_search_lib)


add_executable(parallel_search_example src/main.c)
target_include_directories(parallel_search_example PRIVATE ${ROOT_CMAKE_DIR}/search_libs/include)
target_link_libraries(parallel_search_example PRIVATE parallel_search_lib)

