/*
** EPITECH PROJECT, 2025
** day7
** File description:
** write the funcions to copy in the strings
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}
