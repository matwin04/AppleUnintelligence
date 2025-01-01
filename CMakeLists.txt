cmake_minimum_required(VERSION 3.15)

# Project name
project(SerialD VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/avr.cpp
)

set(HEADERS
    src/avr.h
)
find_package(Crow)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PUBLIC Crow::Crow)