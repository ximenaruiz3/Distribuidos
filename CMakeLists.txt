cmake_minimum_required(VERSION 3.9)
project(ProyectoSD)

SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_STANDARD 11)

add_executable(ProyectoSD
        ClientInfo.hpp
        Server.hpp
        Client.hpp
        ReciveFiles.hpp
        SendFiles.hpp
        Server.cpp
        Client.cpp
        ClientInfo.cpp
        SendFiles.cpp
        ReciveFiles.cpp
        main.cpp
        )