cmake_minimum_required(VERSION 3.14)
project(inverseKinematics)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-no-pie")

add_executable(${PROJECT_NAME} main.cpp armComonent.cpp armComonent.h arm.cpp arm.h calculations.cpp calculations.h)

