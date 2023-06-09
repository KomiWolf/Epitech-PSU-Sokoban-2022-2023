/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** strncpy
*/

#include "./my.h"

char * my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (src[a] != '\0' && a < n) {
        a = a + 1;
    }
    for (a = 0; a < n; a++) {
        dest[a] = src[a];
    }
    dest[a] = '\0';
    return dest;
}
