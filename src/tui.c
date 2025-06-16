#include "gameUtils.h"

void startUI();
void printGrid(WINDOW*);
void userInput();


void startUI()
{
    noecho();
    curs_set(0);
   

    WINDOW *win = newwin(ROWS, COLS, 0, 0);
    box(win, ACS_VLINE, ACS_HLINE); 
    while(1)
    {
        box(win, ACS_VLINE, ACS_HLINE);
        checkCells();
        printGrid(win);
        //refresh();
        wrefresh(win);
        sleep(1);
    }    
}

void printGrid(WINDOW *win)
{
    start_color();
    //Defining colors
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // white background
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // black background

    for (int i = 1; i < ROWS-1; i++){
        for (int j = 1; j < COLS-1; j++){

            if (grid[i][j] == 1)
            {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, i , j , " ");
                wattroff(win, COLOR_PAIR(1));
            }else
            {
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, i , j , " ");
                wattroff(win, COLOR_PAIR(2));
            }

        }
        putchar('\n');
    }
}

void userInput()
{
    

}
