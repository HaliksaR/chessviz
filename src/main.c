#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"

void help_print();
void info_print();

char q;

int main() {
    int i = 0;
    char places[6];
    int exitt = 0;
    info_print();
    while ( i == 0) {
        system("clear");
        info_print();
        printf("\t    %s(s) Start or (q) Quit\n%s", GREEN, RESET);
        printf("\t\t Command : ");
        scanf("%c", &q);
        system("clear");
        print_new_board();
        if (q == 's') {
            i = -1;
            while (exitt == 0) {
                help_print();
                printf("Write coordinates of the figure and \n   where to put it."
                " Example a2-c8\n""\t%s      Command: ", GREEN);
                scanf("%s", places);
                printf("%s", RESET);
                if (places[0] == 'r') {
                    system("clear");
                    exitt = 1;
                    main();
                }
                system("clear");
                exitt = board_func(places);
                if (exitt == -1) {
                    print_board();
                    printf("%s\tWrong coordinates or way!\n%s", RED, RESET);
                    exitt = 0;
                    printf("%s", places);
                    printf(" %c", q);
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
    printf("\t%s      (r)Restart\n\n%s", GRAY, RESET);
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