#include "tui.h"
#include "game.h"
#include <stdio.h>

int main()
{
    game_init_random();
    tui_print_board();
    
    // tui_init();
    // int selected = tui_main_menu();
    // tui_quit();

    // // For now, just print result in the terminal after quitting curses
    // const char *options[] = {"DRAW", "RANDOM", "EXIT"};
    // printf("Selected: %s\n", options[selected]);

    return 0;
}
