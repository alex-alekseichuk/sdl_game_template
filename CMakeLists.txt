cmake_minimum_required(VERSION 3.15)
project(2d_game C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

find_package(SDL3 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)

add_executable(snake src/snake.c
        src/model/model.h
        src/model/model.c
        src/view/game_view.h
        src/view/game_view.c
)

target_link_libraries(snake SDL3::SDL3)
