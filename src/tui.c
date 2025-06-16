#include <ncurses.h>
#include "tui.h"

#define MENU_ITEMS 3

const char *menu_options[MENU_ITEMS] = {"DRAW", "RANDOM", "EXIT"};

void tui_init() {
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE); // Enable arrow keys
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // White background
}

void tui_quit() {
    endwin();
}

int tui_main_menu() {
    int choice = 0;
    int ch;

    while (1) {
        clear();
        for (int i = 0; i < MENU_ITEMS; i++) {
            if (i == choice) {
                attron(COLOR_PAIR(1));
                mvprintw(3 + i, 4, "%s", menu_options[i]);
                attroff(COLOR_PAIR(1));
            } else {
                mvprintw(3 + i, 4, "%s", menu_options[i]);
            }
        }
        refresh();

        ch = getch();
        switch (ch) {
            case KEY_UP:
                choice = (choice == 0) ? MENU_ITEMS - 1 : choice - 1;
                break;
            case KEY_DOWN:
                choice = (choice == MENU_ITEMS - 1) ? 0 : choice + 1;
                break;
            case 10: // ENTER key
            case KEY_ENTER:
                return choice;
            default:
                break;
        }
    }
}
