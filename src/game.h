#ifndef GAME_H

#define GAME_H

extern int board_height, board_width;
extern int **board;

void game_alloc_board();
void game_free_board();
void game_init_random();
void game_init_empty();
void game_step();
int game_get_cell();
void game_set_cell(int x, int y, int state);

#endif