cmake_minimum_required(VERSION 3.8)

add_subdirectory(src)
add_subdirectory(runner)
add_subdirectory(tests)
enable_testing()
add_test(NAME MY_TEST COMMAND my_tests)