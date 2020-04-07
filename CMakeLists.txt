cmake_minimum_required(VERSION 3.15)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(ConnectFour main.cpp)