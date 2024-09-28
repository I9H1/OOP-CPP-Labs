cmake_minimum_required(VERSION 3.26)
project(task_0)

set(CMAKE_CXX_STANDARD 11)

add_executable(task_0 main.cpp
        FileReader.h
        FileReader.cpp
        Statistics.h
        Statistics.cpp
        Tokenizer.h
        Tokenizer.cpp
        Controller.h
        Controller.cpp
        FileWriter.h
        FileWriter.cpp)
