#include "gameUtils.h"

int main()
{

    populateGrid();

    initscr();
    startUI();
    getch();
    endwin();

    return 0;
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
    grid[r + 1][c - 1] = 1;
    grid[r + 1][c + 1] = 1;
}