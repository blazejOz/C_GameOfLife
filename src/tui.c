#include "tui.h"
#include "game.h"

#define MENU_ITEMS 3

WINDOW *main_board_win = NULL; // Define global window

const char *menu_options[MENU_ITEMS] = {"DRAW", "RANDOM", "EXIT"};

void tui_init() {
    initscr();
    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    main_board_win = newwin(BOARD_HEIGHT+2, BOARD_WIDTH+2, 1, 1);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // WHITE BACK GROND
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // BLACK BACK GROUND
    init_pair(3, COLOR_RED, COLOR_BLACK); // RED TEXT
}

void tui_quit() {
    delwin(main_board_win);
    endwin();
}

int tui_main_menu() {
    int choice = 0, ch;

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

void tui_draw_mode() {
    keypad(main_board_win, TRUE);
    int cur_y = 0, cur_x = 0;
    while(1){
        box(main_board_win, 0, 0);
        tui_print_board(main_board_win);
        wattron(main_board_win, COLOR_PAIR(3));
        mvwaddch(main_board_win, cur_y + 1, cur_x + 1, 'X');
        wattroff(main_board_win, COLOR_PAIR(3));
        wrefresh(main_board_win);
        int ch = wgetch(main_board_win);

        switch (ch) {
            case 'w':
            case KEY_UP:    if (cur_y > 0) cur_y--; break;
            case 's':
            case KEY_DOWN:  if (cur_y < BOARD_HEIGHT - 1) cur_y++; break;
            case 'a':
            case KEY_LEFT:  if (cur_x > 0) cur_x--; break;
            case 'd':
            case KEY_RIGHT: if (cur_x < BOARD_WIDTH - 1) cur_x++; break;
            case 'q':       return; // exit draw mode
            case ' ':
                game_set_cell(cur_y, cur_x, !game_get_cell(cur_y, cur_x));
                break;
            case 10:
            case KEY_ENTER:
                tui_run_simulation();
        }
    }
}

void tui_run_simulation() {
    nodelay(stdscr, TRUE);
    while (1){
        box(main_board_win, 0, 0);
        tui_print_board(main_board_win);
        wrefresh(main_board_win);
        napms(100);
        int ch = getch();
        if (ch == 'q' || ch == 'Q')
            break;
        game_step();
    }
    nodelay(stdscr, FALSE);
}

void tui_print_board(WINDOW *win) {
    for(int y = 0; y < BOARD_HEIGHT; y++) {
        for(int x = 0; x < BOARD_WIDTH; x++) {
            int cell = game_get_cell(y, x);
            if(cell ==  1){
                wattron(win, COLOR_PAIR(1));
                mvwaddch(win, y+1, x+1, ' ');
                wattroff(win, COLOR_PAIR(1));
            } else {
                wattron(win, COLOR_PAIR(2));
                mvwaddch(win, y+1, x+1, ' ');
                wattroff(win, COLOR_PAIR(2));
            }
        }
    }
}
