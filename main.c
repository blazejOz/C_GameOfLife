#include <stdio.h>
#include <stdlib.h>

#define ROWS 30
#define COLS 50

int grid[ROWS][COLS] = {0};

void populateGrid();
void checkCells();
int aliveNeighbours(int,int);
void printGrid();

int main()
{
    populateGrid();
    printGrid();
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
}

void checkCells()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = aliveNeighbours(i,j);
        }
        putchar('\n');
    }
}

int aliveNeighbours(int ,int)
{


}

void printGrid()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
                printf("\033[47m  ");
            else
                printf("\033[0m  ");
        }
        putchar('\n');
    }
}
