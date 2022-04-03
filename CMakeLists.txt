cmake_minimum_required(VERSION 3.12)
project(RT)

set(CMAKE_CXX_STANDARD 14)

add_executable(RT TGAImage.cpp Vector3.cpp Color.cpp main.cpp)
