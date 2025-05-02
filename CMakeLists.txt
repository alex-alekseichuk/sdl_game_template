cmake_minimum_required(VERSION 3.15)
project(snake C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

find_package(SDL3 CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.c
        src/model/game.h
        src/model/game.c
        src/view/game_view.h
        src/view/game_view.c
        src/controller/controller.h
        src/controller/controller.c
        src/control/game_control.h
        src/control/game_control.c
)
target_link_libraries(${PROJECT_NAME} SDL3::SDL3)

add_executable(hello_world src/hello_world.c)
target_link_libraries(hello_world SDL3::SDL3)
