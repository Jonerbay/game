cmake_minimum_required(VERSION 3.23)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game main.cpp Square.cpp Square.h Puzzle.cpp Puzzle.h)
