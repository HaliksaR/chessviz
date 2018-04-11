#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "check_strokes.h"

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
                " Example a2 c8\n\n""\t  Command 1: ");
                scanf("%s", one_place);
                if (one_place[0] == 'r') {
                    system("clear");
                    exit = 1;
                    main();
                }
                printf("\n\t  Command 2: ");
                scanf("%s", two_place);
                system("clear");
                exit = board_func(one_place, two_place);
                if (exit == -1) {
                    print_new_board();
                    printf("%s\t   Wrong coordinates!\n%s", RED, RESET);
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
    printf("\t%s       (r)Restart\n\n%s", GRAY, RESET);
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

    printf("%s\t\tby  HaliksaR\n%s", GRAY, RESET);
    printf("%s\t        Beta version\n\n\n%s", GRAY, RESET);
}