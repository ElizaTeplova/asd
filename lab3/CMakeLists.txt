cmake_minimum_required(VERSION 3.0)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp Sorters/Sorter.h PDT/PDTTestObject.h PDT/node.h Sorters/TournamentSort.h)
