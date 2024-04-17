cmake_minimum_required(VERSION 3.10)
project(dot_reaction)

set(SOURCES src/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(raylib REQUIRED)

target_link_libraries(${PROJECT_NAME} raylib)
