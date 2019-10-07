cmake_minimum_required(VERSION 3.4)

project(social_network)

set (CMAKE_CXX_STANDARD 11)


#list includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/unittests)

#list sources
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB UNITTESTS "${CMAKE_CURRENT_SOURCE_DIR}/unittests/*.cpp")
file(GLOB main "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

#list sources
add_executable(social_network ${main} ${UNITTESTS} ${SOURCES})
