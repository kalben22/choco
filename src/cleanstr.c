/*
** EPITECH PROJECT, 2026
** execute process
** File description:
** minishell
*/

#include "../include/my.h"

char    *cleanstr(char *str)
{
    int i;
    int j;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    j = 0;
    while (str[i])
        str[j++] = str[i++];
    str[j] = '\0';
    return (str);
}