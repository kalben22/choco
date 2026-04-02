/*
** EPITECH PROJECT, 2025
** day8
** File description:
** script files to allocate memory and copies
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int j = 0;
    int i = 0;
    char *dest;

    if (src == NULL)
        return NULL;
    while (src[i] != '\0')
        i++;
    dest = malloc((i + 1) * sizeof(char));
    while (src[j] != '\0') {
        dest[j] = src[j];
        j++;
    }
    dest[j] = '\0';
    return dest;
}
