cmake_minimum_required(VERSION 3.24)
project(Advanced_Programming_1___Exercise_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Client)
include_directories(Server)

add_executable(Advanced_Programming_1___Exercise_2
        Client/Client.cpp
        Client/Client.h
        Client/ClientFront.cpp
        Client/ClientFront.h
        Server/Server.cpp
        Server/Server.h
        Server/ServerFront.cpp
        Server/ServerFront.h
        ClassifyFlower.cpp
        ClassifyFlower.h
        CreateClassifiedFiles.cpp
        CreateClassifiedFiles.h
        DistanceCalculator.cpp
        DistanceCalculator.h
        Flower.cpp
        Flower.h
        KNN.cpp
        KNN.h
        Main.cpp
        ReadFlowers.cpp
        ReadFlowers.h)
