cmake_minimum_required(VERSION 2.8)

project(tests)

enable_testing()

add_executable(test_wide_system test_wide_system.c)
target_link_libraries(test_wide_system wide_system)

add_test(test_wide_system test_wide_system)

