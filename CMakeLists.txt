cmake_minimum_required(VERSION 3.20)
project(Advanced_Programming_1___Exercise_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Advanced_Programming_1___Exercise_2
        DistanceCalculator.cpp
        DistanceCalculator.h
        Flower.cpp
        Flower.h
        KNN.cpp
        KNN.h
        ReadFlowers.cpp
        ReadFlowers.h
        ClassifyFlower.cpp
        ClassifyFlower.h
        CreateClassifiedFiles.cpp
        CreateClassifiedFiles.h
        Main.cpp
        Main.h)

add_executable(Server 
               Server.h
               Server.cpp)
