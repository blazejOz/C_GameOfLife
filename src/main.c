#include "tui.h"
#include "game.h"

int main()
{
    tui_init();
    while(1){
        int choice = tui_main_menu(); // return menu choice
        if (choice == 0) {
            // DRAW
        } else if (choice == 1) {
            // RANDOM 
            game_init_random();
            tui_run_simulation();
        } else if (choice == 2) {
            // EXIT
            break;
        }
    }
    tui_quit();
    return 0;
}