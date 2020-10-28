
include_directories(include)

set(COMMON_SRC "${CMAKE_CURRENT_SOURCE_DIR}/common_files/src")
set(COMMON_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/common_files/include")

include_directories(${COMMON_INCLUDE})

add_subdirectory(parallel_search_lib)
add_subdirectory(sequential_search_lib)




#тестирование общих функций библиотеки
set(CMAKE_CXX_STANDARD 11)

add_executable(common_files_tests tests/common_files_tests.cpp common_files/src/for_searchers.c)
target_include_directories(common_files_tests PRIVATE ${COMMON_INCLUDE})
find_package(GTest REQUIRED)
target_include_directories(common_files_tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(common_files_tests ${GTEST_LIBRARIES} pthread)



