cmake_minimum_required(VERSION 3.17)
project(orderComputerRoom)

set(CMAKE_CXX_STANDARD 14)

add_executable(orderComputerRoom main.cpp Student.cpp teacher.cpp manager.cpp computerRoom.cpp)