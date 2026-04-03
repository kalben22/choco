/*
** EPITECH PROJECT, 2026
** execute command
** File description:
** minishell
*/

#include "../include/my.h"

char *recup_home(char **env)
{    
    char *token = NULL;
        int i = 0;

    while (env[i] != NULL) {
    token = strtok(env[i], "=");
        if (my_strcmp(token, "HOME") == 0) {return my_strdup(env[i] + 5);}
        i++;
    }
    return NULL;
}

int cf_function(char **tab, char **env)
{
    char *home = NULL;

    if (my_strcmp(tab[0], "cd") == 0) {
        if (tab[1] == NULL) {
            home = recup_home(env);
            chdir(home);
        }
        if (tab[2] != NULL) {
            mini_printf("%s: Too many arguments.\n", tab[2]);
            return 1;
        }
        if (chdir(tab[1]) != 0) {
            mini_printf("%s:  No such file or directory.\n", tab[1]);
            return 1;
        }
    }
    return 0;
}

int exec_cmd(char **tab, char **env)
{
    int i = 0;
    char *home = NULL;

    if (tab == NULL)
        return 0;
    if (cf_function(tab, env) != 0)
        return 1;
    if (my_strcmp(tab[0], "env") == 0) {
        while (env[i] != NULL) {
            mini_printf("%s\n", env[i]);
            i++;
        }
        return 1;
    }
    return 0;
}
