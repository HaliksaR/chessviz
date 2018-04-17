#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void help_print();
void info_print();

int main() {
    int i = 0;
    info_print();
    while ( i == 0) {
        system("clear");
        char q;
        info_print();
        printf("\t    %s(s) Start or (q) Quit\n%s", GREEN, RESET);
        printf("\t\t Command : ");
        scanf("%c", &q);
        system("clear");
        print_new_board();
        if (q == 's') {
            i = -1;
            int exit = 0;
            while (exit == 0) {
                char one_place[4], two_place[4];
                help_print();
                printf("Write coordinates of the figure and \n   where to put it."
                " Example a2 c8\n""\t%s      Command: ", GREEN);
                scanf("%s %s", one_place, two_place);
                printf("%s", RESET);
                if (one_place[0] == 'r') {
                    system("clear");
                    exit = 1;
                    main();
                }
                system("clear");
                exit = board_func(one_place, two_place);
                if (exit == -1) {
                    print_board();
                    printf("%s\tWrong coordinates or way!\n%s", RED, RESET);
                    exit = 0;
                }
            }
        } else if (q == 'q') {
            system("clear");
            return 0;
        }
    }  
    return 0;
}


void help_print() {
    printf("\t%s      (r r)Restart\n\n%s", GRAY, RESET);
}

void info_print() {
    system("clear");
    printf("%s"
    "\t  ████──█──█──███──███──███\n"
    "\t  █──█──█──█──█────█────█\n"
    "\t  █─────████──███──███──███\n"
    "\t  █──█──█──█──█──────█────█\n"
    "\t  ████──█──█──███──███──███\n\n"
    "\t████───████──████──████──████\n"
    "\t█──██──█──█──█──█──█──█──█──██\n"
    "\t████───█──█──████──████──█──██\n"
    "\t█──██──█──█──█──█──█─█───█──██\n"
    "\t████───████──█──█──█─█───████\n\n%s", RED, RESET);
    printf("%s\t        Beta version\n\n\n%s", GRAY, RESET);
}