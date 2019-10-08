cmake_minimum_required(VERSION 3.10)

project(student_data_management_system)

#list includes
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/*.h)

#list sources
file(GLOB SOURCES "*.cpp")

#list sources
add_executable(records ${SOURCES})
