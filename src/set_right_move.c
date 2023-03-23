/*
** EPITECH PROJECT, 2023
** set_right_move
** File description:
** psu
*/

#include "../include/my.h"
#include "../include/sokoban.h"

int set_right_condition(char **tab, int i, int j)
{
    if (tab[i][j] == 'P' && tab[i][j + 1] == 'X' &&
    tab[i][j + 2] != '#' && tab[i][j + 2] != 'X' &&
    (tab[i][j + 2] == ' ' || tab[i][j + 2] == 'O')) {
        tab[i][j] = ' ';
        tab[i][j + 1] = 'P';
        tab[i][j + 2] = 'X';
        return 1;
    }
    return 0;
}

int set_right_loop_2(char **tab, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == 'P' && tab[i][j + 1] == '#')
            return 1;
        if (tab[i][j] == 'P' && tab[i][j + 1] == ' ' &&
        (tab[i][j + 2] == ' ' || tab[i][j + 2] == 'O' ||
        tab[i][j + 2] == 'X' || tab[i][j + 2] == '#')) {
            tab[i][j] = ' ';
            tab[i][j + 1] = 'P';
            return 1;
        }
        if (tab[i][j] == 'P' && tab[i][j + 1] == 'O') {
            tab[i][j] = ' ';
            tab[i][j + 1] = 'P';
            return 1;
        }
        if (set_right_condition(tab, i, j) == 1)
            return 1;
    }
    return 0;
}

void set_right_loop(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (set_right_loop_2(tab, i) == 1)
            return;
    }
}

void set_right_move(int c, char **tab)
{
    if (c == KEY_RIGHT) {
        set_right_loop(tab);
    }
}
