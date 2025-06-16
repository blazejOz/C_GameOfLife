#include "tui.h"
#include <stdio.h>

int main()
{
    tui_init();
    int selected = tui_main_menu();
    tui_quit();

    // For now, just print result in the terminal after quitting curses
    const char *options[] = {"DRAW", "RANDOM", "EXIT"};
    printf("Selected: %s\n", options[selected]);

    return 0;
}
