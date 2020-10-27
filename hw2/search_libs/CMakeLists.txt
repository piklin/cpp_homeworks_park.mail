include_directories(include)

set(COMMON_SRC "${CMAKE_CURRENT_SOURCE_DIR}/common_files/src")
set(COMMON_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/common_files/include")

include_directories(${COMMON_INCLUDE})

add_subdirectory(parallel_search_lib)
add_subdirectory(sequential_search_lib)
