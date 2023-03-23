/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** cpool
*/

#include <unistd.h>

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 1;
    while (str[i] != '\0') {
        if (!((str[i] >= 32 && str[i] <= 126)))
            return 0;
        i++;
    }
    return 1;
}
