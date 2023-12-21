cmake_minimum_required(VERSION 3.25)
project(Teaching_Planning)

set(CMAKE_CXX_STANDARD 17)

add_executable(Teaching_Planning main.cpp
        Exception.h
        Tool.h
        Tool.cpp
        ALGraph.h
        CourseManagement.cpp
        CourseManagement.h
        Menu.cpp
        Menu.h
        Course.h
        Course.cpp
)
