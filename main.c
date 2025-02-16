#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>


#define ROWS 20
#define COLS 30

int grid[ROWS][COLS] = {0};

void start();
void populateGrid();
void checkCells();
int aliveNeighbours(int,int);
void printGrid();

int main()
{


    populateGrid();  

    initscr();
    start_color();
    //Defining colors
    init_pair(1, COLOR_BLACK, COLOR_WHITE); // white background
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // black background

    WINDOW *win = newwin(ROWS, COLS, 0, 0);
    box(win, ACS_VLINE, ACS_HLINE); 
    while(1)
    {
        box(win, ACS_VLINE, ACS_HLINE);
        checkCells();
        printGrid(win);
        refresh();
        wrefresh(win);
        sleep(1);
    }    
    getch();
    endwin();

    // while(1){
    //     checkCells();
    //     printGrid();
    //     sleep(1);
    // }

    return 0;
}

void start()
{
    

}

void populateGrid()
{
    int r = rand() % ((ROWS - 2) - 1 + 1) + 1;
    int c = rand() % ((COLS - 2) - 1 + 1) + 1;

    grid[r][c] = 1;
    grid[r - 1][c - 1] = 1;
    grid[r - 1][c + 1] = 1;
    grid[r - 1][c - 2] = 1;
    grid[r + 1][c] = 1;
    grid[r + 1][c-1] = 1;
    grid[r + 1][c+1] = 1;
    
}

void checkCells()
{
    int tempGrid[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            tempGrid[i][j] = aliveNeighbours(i,j);
        }
    }

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            grid[i][j] = tempGrid[i][j];
            tempGrid[i][j] = 0;
        }
    }    

}


/*
Function checking surrounding cells for alive ones
(r-1,c-1)|(r-1,c)|(r-1,c+1)
(r  ,c-1)|(r  ,c)|(r  ,c+1)
(r+1,c-1)|(r+1,c)|(r+1,c+1)

serching around cell - grid[r][c]

*/
int aliveNeighbours(int r , int c)
{
    int aliveCount = 0;
    int isAlive = grid[r][c]; //checking if cell is alive or dead

    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue; // skips checking itself

            if( (r+i >= 0 && r+i < ROWS) && (c+j >= 0 && c+j < COLS) )
                if (grid[r+i][c+j] == 1) 
                    aliveCount++;
        }
    }

//Conwey's Game of life Rules

    if(isAlive == 1 && aliveCount < 2 ) 
        return 0;
    
    if(isAlive == 1 && (aliveCount == 2 || aliveCount == 3) )
        return 1; 

    if(isAlive == 1 && aliveCount > 3 ) 
        return 0;

    if(isAlive == 0 && aliveCount == 3 )
        return 1; 

    return isAlive;
}

void printGrid(WINDOW *win)
{
    for (int i = 1; i < ROWS-1; i++){
        for (int j = 1; j < COLS-1; j++){
           
            
            if (grid[i][j] == 1){
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, i, j , " ");
                wattroff(win, COLOR_PAIR(1));
            }else{
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, i , j , " ");
                wattroff(win, COLOR_PAIR(2));
            }    
            
        }
        putchar('\n');
    }
}
