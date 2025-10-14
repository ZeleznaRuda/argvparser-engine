cmake_minimum_required(VERSION 3.10)
project(MainProgram)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# library
add_library(mylib STATIC
    libs/argvparser/src/argvparser.cpp
)

target_include_directories(mylib PUBLIC
    libs/argvparser/include
)

# main program
add_executable(main main.cpp)

target_link_libraries(main PRIVATE mylib)
target_include_directories(main PRIVATE
    libs/argvparser/include
)
