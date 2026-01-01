cmake_minimum_required(VERSION 3.31)
project(LRU)

set(CMAKE_CXX_STANDARD 23)

add_executable(LRU
        main.cpp
        core/entities/LruCache.hpp
        core/entities/BaseCache.hpp
)
