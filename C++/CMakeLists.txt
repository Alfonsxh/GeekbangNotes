cmake_minimum_required(VERSION 3.8)
project(cOrcpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(cOrcpp Paradigm)

set(SOURCE_FILES main.cpp )
add_executable(cOrcpp ${SOURCE_FILES})