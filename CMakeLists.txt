cmake_minimum_required(VERSION 3.21)
project(CardGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(CardGame main.cpp card.h Game.h)
