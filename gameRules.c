#include "gameUtils.h"

int grid[ROWS][COLS] = {0};

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

//Applaying Conwey's Game of life Rules

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

/*
Function checking surrounding cells for alive ones
(r-1,c-1)|(r-1,c)|(r-1,c+1)
(r  ,c-1)|(r  ,c)|(r  ,c+1)
(r+1,c-1)|(r+1,c)|(r+1,c+1)

serching around cell - grid[r][c]

*/

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