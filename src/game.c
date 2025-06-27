#include "game.h"
#include <stdlib.h>

int board_height = 20;
int board_width = 20;
int **board = NULL;

static int count_neighbours(int y, int x);

void game_alloc_board()
{
    board = malloc(board_height * sizeof(int*));
    for (int i = 0; i < board_height; i++) {
        board[i] = malloc(board_width * sizeof(int));
    }

}

void game_free_board() {
    for (int i = 0; i < board_height; i++) {
        free(board[i]);
    }
    free(board);
}

void game_init_random()
{
    // assign random alive/dead cells to game board
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            board[y][x] = rand() % 2; // random 0 or 1
        }
    }
}

void game_init_empty()
{
    // assign 0 to all game board
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            board[y][x] = 0;
        }
    }
}

void game_step()
{
    //step into next generation of cells 

    int copy_board[board_height][board_width];

    //copy board state
    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            copy_board[y][x] = board[y][x];
        }
    }

    for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            int cell = board[y][x];
            int alive_neighbours = count_neighbours(y, x);

            //Apply game of life logic
            if (cell == 1  && alive_neighbours < 2)
                cell = 0;
            else if (cell == 1 && (alive_neighbours == 2 || alive_neighbours == 3))
                cell = 1;
            else if (cell == 1 && alive_neighbours > 3)
                cell = 0;
            else if (cell == 0 && alive_neighbours == 3)
                cell = 1;
            
            // assign new cell to board copy
            copy_board[y][x] = cell;           
        }
    }

    // assign next generetion of cells to game board
     for(int y = 0; y < board_height; y++) {
        for(int x = 0; x < board_width; x++) {
            board[y][x] = copy_board[y][x];
        }
    }

}

int count_neighbours(int y, int x)
{
    // check all surrunding cells, and return alive neighbour count
    int count = 0;
    count += game_get_cell(y-1, x-1);
    count += game_get_cell(y-1, x  );
    count += game_get_cell(y-1, x+1);
    count += game_get_cell(y  , x-1);
    count += game_get_cell(y  , x+1);
    count += game_get_cell(y+1, x-1);
    count += game_get_cell(y+1, x  );
    count += game_get_cell(y+1, x+1);
    return count;
}

int game_get_cell(int y, int x)
{
    // return cell state if in bounds or retrun 0
    if(y >= 0 && y < board_height && x >= 0 && x < board_width) // bound check
        return board[y][x];
    else
        return 0;
}

void game_set_cell(int y, int x, int state)
{
    board[y][x] = state;
}