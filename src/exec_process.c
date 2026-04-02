/*
** EPITECH PROJECT, 2026
** execute process
** File description:
** minishell
*/

#include "../include/my.h"

int chech_buitin(char **tab)
{
    if (my_strcmp(tab[0], "cd") == 0)
        return 1;
    if (my_strcmp(tab[0], "setenv") == 0)
        return 1;
    if (my_strcmp(tab[0], "env") == 0)
        return 1;
    if (my_strcmp(tab[0], "exit") == 0)
        return 1;
    if (my_strcmp(tab[0], "unsetenv") == 0)
        return 1;
    return 0;
}

void void_func(char **tab, char **j)
{
    if (chech_buitin(tab) == 0) {
        if (execute_func(j, tab) == 1)
            process_continu(j, tab);
    }
}

char **exec_process(char **j, char **tab)
{
    int i = 0;
    char **curr_env = NULL;

    if (tab == NULL)
        return NULL;
    if (my_strcmp(tab[0], "exit") == 0) {
        exit(0);
    }
    if (my_strcmp(tab[0], "setenv") == 0) {
        if (check_setenv(tab, j) != 1) {
            curr_env = cpy_env(j, tab);
            return curr_env;
        } else
            return j;
    }
    if (my_strcmp(tab[0], "unsetenv") == 0) {
        curr_env = delete_env(tab, j);
        return curr_env;
    }
    void_func(tab, j);
    return j;
}
