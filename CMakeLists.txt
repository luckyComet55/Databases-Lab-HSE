cmake_minimum_required(VERSION 3.10)

project(luckygres VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_LIST src/dbms/FileStructure.hpp src/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
