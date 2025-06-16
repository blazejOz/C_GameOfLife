cmake_minimum_required(VERSION 3.10)
project(pc_hardware_monitor)

set(CMAKE_C_STANDARD 99)

# Add your src directory
add_executable(hardware_monitor
    src/main.c
    src/tui.c
    src/game.c
)

# Link with ncurses
find_package(Curses REQUIRED)
target_include_directories(hardware_monitor PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(hardware_monitor PRIVATE ${CURSES_LIBRARIES})