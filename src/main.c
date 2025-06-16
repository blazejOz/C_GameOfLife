#include "tui.h"
#include "game.h"
#include <stdio.h>
#include <ncurses.h>

int main()
{
    tui_init();
    game_init_random();
    tui_print_board();
    getch();
    game_step();
    tui_print_board();
    getch();
    tui_quit();

    return 0;
}
