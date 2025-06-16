cmake_minimum_required(VERSION 3.10)
project(game_of_life_c)

set(CMAKE_C_STANDARD 99)

# Add your src directory
add_executable(game_of_life
    src/main.c
    src/tui.c
    src/game.c
)

# Link with ncurses
find_package(Curses REQUIRED)
target_include_directories(game_of_life PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(game_of_life PRIVATE ${CURSES_LIBRARIES})