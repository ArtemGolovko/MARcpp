cmake_minimum_required(VERSION 3.5)

project(mar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB 
    CPP_SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${CPP_SRC})