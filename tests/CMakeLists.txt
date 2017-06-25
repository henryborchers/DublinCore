#add_subdirectory(Catch)
add_executable(my_tests my_tests.cpp)
target_include_directories(my_tests PRIVATE Catch/include)
target_link_libraries(my_tests DublinCore)