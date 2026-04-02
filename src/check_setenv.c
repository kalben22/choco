/*
11;rgb:3030/0a0a/2424** EPITECH PROJECT, 2026
** minishell
** File description:
** check_setenv
*/

#include "../include/my.h"
int isanum   (char *c)
{
    int i = 0;

    while (c[i] != '\0') {
        
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')
            || c[i] == '_' || (c[i] >= '0' && c[i] <= '9'))
            i++;
        else
            return -1;
    }
    return 1;
}

int my_strisalpha(char *c)
{
    int i = 0;

    if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        return 1;
    if (c[i] == '_')
        return 1;
    return -1;
}

int check_arg(char **env, char **tab, int i)
{
    int k = 0;

    if (i == 1) {
        for (k = 0; env[k] != NULL; k++)
            mini_printf("%s\n", env[k]);
        return 1;
    }
    i = 1;
    if (my_strisalpha(tab[i]) == -1) {
        mini_printf("%s: Variable name must begin with a letter.\n",
            tab[0]);
        return 1;
    }
    if (isanum(tab[i]) == -1) {
        mini_printf("%s: Variable name must contain alphanumeric characters.\n",
            tab[0]);
        return 1;
    }
    return 0;
}

int check_setenv(char **tab, char **env)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    if (i > 3) {
        mini_printf("%s: Too many arguments.\n", tab[0]);
        return 1;
    }
    if (check_arg(env, tab, i) == 1)
        return 1;
    return 0;
}
