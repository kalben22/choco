/*
** EPITECH PROJECT, 2026
** execute func
** File description:
** minishell
*/

#include "../include/my.h"

int execute_func(char **env, char **cmd)
{
    char *path = malloc(sizeof(char) * 50);
    int i = 0;
    char **tab = new_path(env);

    if (access(cmd[0], X_OK) == 0)
        return 1;
    while (tab[i] != NULL) {
        my_strcpy(path, tab[i]);
        my_strcat(path, "/");
        my_strcat(path, cmd[0]);
        if (access(path, X_OK) == 0) {
            free(cmd[0]);
            cmd[0] = my_strdup(path);
            free(path);
            return 1;
        }
        i++;
    }
    mini_printf("%s: Command not found.\n", cmd[0]);
    return 0;
}
