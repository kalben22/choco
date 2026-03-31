/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** new_env
*/

#include "../include/my.h"

char **new_env(char **env)
{
    char **new = NULL;
    int i = 0;
    int k = 0;

    while (env[i] != NULL)
        i++;
    new = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (env[i] != NULL) {
        new[i] = my_strdup(env[i]);
        i++;
    }
    new[i] = NULL;
    return new;
}
