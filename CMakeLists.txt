project(stackvector)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

#add_definitions(-DDEBUG)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O3")


set(SRC_LIST ${SRC_LIST}
    ./stack_vector.h
    ./stack_vector2.h
    ./Debug.h
    ./TimeHelper.h
    ./samplemodule.h
    ./samplemodule.cpp
    ./Defines.h
)


add_executable(${PROJECT_NAME} ${SRC_LIST})

