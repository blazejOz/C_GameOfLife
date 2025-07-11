#include "tui.h"
#include "game.h"

#define MENU_ITEMS 3

WINDOW *main_board_win = NULL; // Define global window

const char *menu_options[MENU_ITEMS] = {"DRAW", "RANDOM", "EXIT"};

void tui_init() {
    initscr();
    int term_height , term_width;
    getmaxyx(stdscr, term_height, term_width); // get terminal sized

    board_height = term_height - 4;
    board_width = term_width - 4;
    game_alloc_board();

    noecho();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    main_board_win = newwin(board_height+2, board_width+2, 1, 1);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // WHITE BACK GROND
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // BLACK BACK GROUND
    init_pair(3, COLOR_RED, COLOR_BLACK); // RED TEXT
}

void tui_quit() {
    game_free_board();
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
            case 's':
            case KEY_UP:
                choice = (choice == 0) ? MENU_ITEMS - 1 : choice - 1;
                break;
            case 's':
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
        // X icon setup
        wattron(main_board_win, COLOR_PAIR(3));
        mvwaddch(main_board_win, cur_y + 1, cur_x + 1, 'X');
        wattroff(main_board_win, COLOR_PAIR(3));

        wrefresh(main_board_win);
        int ch = wgetch(main_board_win);

        switch (ch) {
            case 'w':
            case KEY_UP:    if (cur_y > 0) cur_y--; break;
            case 's':
            case KEY_DOWN:  if (cur_y < board_height - 1) cur_y++; break;
            case 'a':
            case KEY_LEFT:  if (cur_x > 0) cur_x--; break;
            case 'd':
            case KEY_RIGHT: if (cur_x < board_width - 1) cur_x++; break;
            case 'q':       return; // exit draw mode
            case ' ': // toggle alive/dead cells
                game_set_cell(cur_y, cur_x, !game_get_cell(cur_y, cur_x));
                break;
            case 10:
            case KEY_ENTER: // start 
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
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
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
