/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** unsetenv
*/

#include "../include/my.h"

char **split_name(char *name, char **env)
{
    char **tmp_env = new_env(env);
    int i = 0;
    int len = my_strlen(name);

    while (tmp_env[i] != NULL) {
        if (my_strncmp(tmp_env[i], name, len) == 0) {
            free(tmp_env[i]);
            tmp_env[i] = NULL;
            break;
        }
        env[i] = my_strdup(tmp_env[i]);
        i++;
    }
    for (; env[i] != NULL; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return env;
}

char **delete_env(char **tab, char **env)
{
    int i = 1;
    char **new_env = NULL;

    while (tab[i] != NULL) {
        new_env = split_name(tab[i], env);
        i++;
    }
    if (tab[1] == NULL) {
        mini_printf("Too few arguments\n");
        return env;
    }
    return new_env;
}
