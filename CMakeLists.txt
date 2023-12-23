cmake_minimum_required(VERSION 3.28)
project(text_data_converter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(DataTypes)

add_executable(text_data_converter main.cpp)

target_link_libraries(text_data_converter DataTypes)