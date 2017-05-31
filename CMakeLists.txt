cmake_minimum_required(VERSION 2.9)

add_definitions(-mtune=native)
add_definitions(-Wall)
add_definitions(-O3)

include_directories(".")

add_definitions(-std=c++14)
add_executable(ivp-exp         examples/exp.cc)


