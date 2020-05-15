cmake_minimum_required(VERSION 3.15)
project(markov-cut-ups)

# Set compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -g -std=c++17 -lstdc++fs")


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_FILES
    	src/Options.cpp
        src/Dictionary.cpp 
	include/Dictionary.h 
	src/main.cpp)

# Make the project root directory the working directory when we run
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(markov-cut-ups ${SOURCE_FILES})

target_link_libraries(markov-cut-ups stdc++fs)
