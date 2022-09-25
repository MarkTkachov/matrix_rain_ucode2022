#include "../inc/header.h"

int main(int argc, char *argv[]) {
    //check for valid usage TODO
    if (argc != 1) {
        mx_printerr("usage: ./matrix_rain\n");
        exit(0);
    }
    if (argv[0]) {}
    //Japanese locale
    setlocale(LC_CTYPE, "ja_JP.UTF-8");
    //init ncurses
    initscr();
    start_color();
    noecho();
    halfdelay(2);
    curs_set(0);
    mx_intro();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    erase();
    srand(time(NULL));
    
    //create linked list with the first tails
    t_list *trails = NULL;
    mx_add_trails(&trails, 10);
    while(1) {
        mx_exit_check();
        //check if user inputed 'q' - exit the loop
        //parse any other user input
        //usleep(50000);
        
        erase();
        mx_add_trails(&trails, 1);
        mx_update_trails(trails);
        mx_print_trails(trails);
        
        refresh();
    }
    
    //refresh();

    //the infinite loop
    //while (1) {
        //check if user inputed 'q' - exit the loop
        //parse any other user input

        //add delay between the frames 

        //update the trails to their new location
        //display the trails 
        //show the new screen
    //}
    
    getch();
    endwin();
    mx_free_trails(&trails);  
    //free the memory
    //end program execution
}

