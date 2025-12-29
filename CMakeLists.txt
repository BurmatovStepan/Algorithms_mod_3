cmake_minimum_required(VERSION 3.23)

project("Task_3")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /sdl /permissive-)
