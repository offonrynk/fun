cmake_minimum_required(VERSION 3.10)

project(student_data_management_system)
file(GLOB SOURCES "*.cpp")
add_executable(records ${SOURCES})
