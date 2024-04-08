cmake_minimum_required(VERSION 3.27)
project(projekcik)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekcik main.cpp
        StackArray.h
        StackArray.cpp
        StackList.h
        StackList.cpp
        Test.h
        Test.cpp
)
