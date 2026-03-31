/*
** EPITECH PROJECT, 2026
** function for free
** File description:
** minshell
*/

#include "../include/my.h"

void func_free(char **tab, char *line)
{
    int i = 0;

    if (line != NULL)
        free(line);
    if (tab == NULL)
        return;
    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
