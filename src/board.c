#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "board.h"

char **container;

char **_board() {
    container = (char**) malloc(9 * sizeof(char*));
    int i,j;
    for (i = 0; i < 9; i++) {
        container[i] = (char*)malloc(9 * sizeof(char));
        for (j = 0; j < 9; j++) {
            container[i][j] = ' ';
        }
    }
    char gl[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    char p = 'p';
    // цыфры 
    for (i = 0; i < 8; i++) {
        container[i][0] = 56 - i;
    }
    // буквы
    for (i = 1; i < 9; i++) {
        container[8][i] = 96 + i;
    }

    for (i = 1; i < 9; i++) {
        container[0][i] = gl[i-1];
        container[7][i] = gl[i-1] - 32;
        container[1][i] = p;
        container[6][i] = p - 32;
    }      
    return container; 
}

void print_new_board() {
    char **nb;
    nb = _board();
    print_board(nb);
}

void print_board(char **container) {
    system("clear");
    printf("\n");
    for (int i = 0; i < 9; i++) {
        printf("\t  ");
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                printf("%s%c %s", cyan, container[i][j], RESET);
            } else if (i == 8) {
                printf("%s%c %s", cyan, container[i][j], RESET);
            } else {
                printf("%c ", container[i][j]);
            }
        }
        printf("\n");
    } 
}
char** movePawn(char **v, int* pozition) { 
    int poz = container[pozition[1]][pozition[0]];
    container[pozition[1]][pozition[0]] = container[pozition[3]][pozition[2]];
    container[pozition[3]][pozition[2]] = poz;
    return v;
}

int board_func(char *one_place, char *two_place) {
    int pozition[4];
    container = _board();
    pozition[0] = one_place[0] - 96; //a
    pozition[1] = 9 - (one_place[1] - 48) - 1; //2
    pozition[2] = two_place[0] - 96; //c
    pozition[3] = 9 - (two_place[1] - 48) - 1; //8
    printf("\n ");

    for(int g = 0; g < 4; g++) {
        if (pozition[g] < 0 || pozition[g] > 9) {
            return -1;
        }
    }
    container = movePawn(container, pozition);
    print_board(container);
    return 0;
}
