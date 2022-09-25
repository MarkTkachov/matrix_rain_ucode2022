#include "../inc/header.h"

void mx_exit_check() {
    if(getch() == 'q'){
        endwin();
        exit(1);
    }
}

