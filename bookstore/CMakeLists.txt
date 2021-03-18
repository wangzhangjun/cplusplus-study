cmake_minimum_required(VERSION 3.17)
project(bookstore)

set(CMAKE_CXX_STANDARD 14)
set(INC_DIR /usr/local/include/)

include_directories(${INC_DIR})

add_executable(bookstore main.cpp)