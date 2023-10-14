cmake_minimum_required(VERSION 3.10)

project(luckygres VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
    SRC_LIST
    src/Types/Meta/Constants.hpp
    src/Types/Meta/Uuid.hpp
    src/Types/Meta/Uuid.cpp
    src/dbms/EntityManager.hpp
    src/dbms/EntityManager.cpp
    src/dbms/Container.hpp
    src/dbms/Container.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
