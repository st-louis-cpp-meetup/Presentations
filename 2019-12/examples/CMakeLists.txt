cmake_minimum_required(VERSION 3.8)
project(fmt-examples)
set(CMAKE_CXX_STANDARD 17)

find_package(fmt)

add_executable(hello_world 01_hello_world.cpp)
target_link_libraries(hello_world fmt::fmt)

# add_executable(hello_world_std 02_hello_world_std.cpp)

add_executable(hello_world_fmt 03_hello_world_fmt.cpp)
target_link_libraries(hello_world_fmt fmt::fmt)

add_executable(basic_types 04_basic_types.cpp)
target_link_libraries(basic_types fmt::fmt)

add_executable(format_string 05_format_string.cpp)
target_link_libraries(format_string fmt::fmt)

add_executable(output_iterator 06_output_iterator.cpp)
target_link_libraries(output_iterator fmt::fmt)

add_executable(formatter_specializations 07_formatter_specializations.cpp)
target_link_libraries(formatter_specializations fmt::fmt)

add_executable(error_handling 08_error_handling.cpp)
target_link_libraries(error_handling fmt::fmt)
