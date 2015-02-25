project(chunklist)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)


# -ftree-vectorize -march=native -ffast-math -use_fast_math --ptxas-options=-v
#add_definitions(-DDEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -ftree-vectorize -march=native -ffast-math -use_fast_math")


set(SRC_LIST ${SRC_LIST}
    ./chunk.h
    ./Defines.h
    ./Allocators.h
    ./Allocators.cpp
    ./nasty_list.h
    ./chunk_list.h
    ./Debug.h
    ./TimeHelper.h
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

