//#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define ROWS 20
#define COLS 30

extern int grid[ROWS][COLS];

void startUI();
void checkCells();
int aliveNeighbours(int,int);
void populateGrid();
