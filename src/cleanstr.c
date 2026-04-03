/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** cleanstr
*/

#include "../include/my.h"

void tab_equal(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '\t')
            str[i] = ' ';
}

char *cleanstr(char *str)
{
    int j = 0;
    int i = 0;
    char *src = my_strdup(str);
    char *dest = malloc(sizeof(char) * 4096);

    tab_equal(src);
    while (src[i] == ' ')
        i++;
    while (src[i] != '\0' && src[i] != '\n') {
        if (src[i] != ' ' || (src[i] == ' ' && src[i + 1] != ' ')) {
            dest[j] = src[i];
            j++;
        }
        i++;
        while (src[i] == ' ' && src[i + 1] == ' ')
            i++;
    }
    dest[j] = '\0';
    return dest;
}
