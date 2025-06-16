#ifndef GAME_H

#define GAME_H

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20
extern int board[BOARD_HEIGHT][BOARD_WIDTH];

void game_init_random();
void game_init_empty();
void game_step();
int game_get_cell_state();
void game_set_cell(int x, int y, int state);

#endif