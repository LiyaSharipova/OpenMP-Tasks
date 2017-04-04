cmake_minimum_required(VERSION 3.6)
project(openmp)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES main.cpp )
add_executable(task1 task1.cpp )
add_executable(task2 task2.cpp)
add_executable(task3 task3.cpp)
add_executable(task4 task4.cpp)
add_executable(task5 task5.cpp)
add_executable(task6 task6.cpp)
add_executable(task7 task7.cpp)
add_executable(task8 task8.cpp)
add_executable(task9 task9.cpp)
add_executable(task10 task10.cpp)
add_executable(task11 task11.cpp)
add_executable(task12 task12.cpp)
add_executable(task13_1 task13_1.cpp)
add_executable(vector  vector.cpp)


find_package(OpenMP)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fopenmp")
#include_directories(${MPI_INCLUDE_PATH})

#SET(CMAKE_C_COMPILER mpicc)
#SET(CMAKE_CXX_COMPILER mpicxx)


#set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES main.c)
#add_executable(hello_world ${SOURCE_FILES})


#set(CXXFLAGS "${CXXFLAGS} -fopenmp")
