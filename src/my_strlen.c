/*
** EPITECH PROJECT, 2025
** strlen
** File description:
** write the function
*/

#include <stdio.h>
#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
