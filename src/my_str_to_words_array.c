/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** radar
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void funct(char **array, int k, int i, char const *str, int j)
{
    int l = 0;
    int deb = 0;

    if (!array[k]) {
        for (l = 0; l < k; l++)
            free(array[k]);
        free(array);
        return;
    }
    for (deb = 0; deb < j; deb++) {
        array[k][deb] = str[i + deb];
    }
    array[k][deb] = '\0';
}

char **comp_tab(int i, int count, char const *str)
{
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (count + 1));

    for (k = 0; k < count; k++) {
        j = 0;
        while (str[i + j] != '\n' && str[i + j] != '\0' && str[i + j] != ' ')
            j++;
        array[k] = malloc((j + 1) * sizeof(char));
        funct(array, k, i, str, j);
        i += j;
        while (str[i] == ' ')
            i++;
    }
    array[k] = NULL;
    return array;
}

char **my_str_to_word_array(char *str, int *nb_rows)
{
    char **array;
    int count = 0;
    int i = 0;

    str = split_1();
    if (str == NULL)
        exit(0);
    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
            count++;
        i++;
    }
    if (count == 0)
        return NULL;
    i = 0;
    array = comp_tab(i, count, str);
    *nb_rows = count;
    return array;
}
