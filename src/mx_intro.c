#include "../inc/header.h"

void mx_intro() {
    init_pair(3,COLOR_GREEN,COLOR_BLACK);
    char *lines[] = {
        "Wake up, Neo...", "The Matrix has you...", "Follow the white rabbit.", "Knock, knock, Neo"
    };
    for (int j = 0; j < 4; j++){
        for (int a = 0; a < mx_strlen(lines[j]); a++){
            mvaddch(0, a, lines[j][a] | COLOR_PAIR(3) | A_BOLD);
            refresh();
            //usleep(1);
                if(getch() == 'q'){
                    echo();
                    endwin();
                    exit(1);
                }
        }
        usleep(1000000);
        clear();
    }
}

