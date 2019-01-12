cmake_minimum_required(VERSION 3.9)
project(sweeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(sweeper main.cpp sweepergrid.cpp sweepergrid.h sweepercell.cpp sweepercell.h)