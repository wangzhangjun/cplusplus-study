cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
project (hello_cmake) #设置工程名

add_executable(client main.cpp cpplang.hpp SpinLock.cpp Zmq.cpp) #生成可执行文件