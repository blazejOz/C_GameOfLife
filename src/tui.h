#ifndef TUI_H
#define TUI_H

#include <ncurses.h>
extern WINDOW *main_board_win;

void tui_init();
void tui_quit();
int tui_main_menu();
void tui_draw_mode(); 
void tui_print_board(WINDOW *win);
void tui_run_simulation();


#endif