#include "game.h"
#include <stdlib.h>

int board[BOARD_HEIGHT][BOARD_WIDTH];

void game_init_random()
{
    for(int y = 0; y < BOARD_HEIGHT; y++) {
        for(int x = 0; x < BOARD_WIDTH; x++) {
            board[y][x] = rand() % 2;
        }
    }
}

void game_init_empty()
{

}

void game_step()
{

}

int game_get_cell_state();
void game_set_cell(int x, int y, int state);