cmake_minimum_required(VERSION 3.27)
project(RepeatProject)

set(CMAKE_CXX_STANDARD 23)

add_executable(RepeatProject main.cpp
        Customer.h
        Customer.cpp)
