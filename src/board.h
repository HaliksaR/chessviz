#ifndef __BOARD_H__
    #define __BOARD_H__

    #define RESET "\033[0m"
    #define green "\033[1;32m"
    #define red   "\033[1;31m"
    #define cyan  "\033[1;36m"
    #define gray  "\033[2m"

    void print_new_board();
    int board_func(char *one_place, char *two_place);
    void print_board(char **container);
#endif