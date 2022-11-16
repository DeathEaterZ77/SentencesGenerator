cmake_minimum_required(VERSION 3.21)
project(SentencesGenerator C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SentencesGenerator
        main.c
        node.c
        node.h
        N-aryCharTree.c
        N-aryCharTree.h
        displayTree.c
        displayTree.h
        automaticgenerator.c
        automaticgenerator.h)

