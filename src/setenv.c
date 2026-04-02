/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** setenv
*/

#include "../include/my.h"

char **up_date(char **new, char *stock, char **env, int i)
{
    new[i] = my_strdup(stock);
    free(env[i]);
i++;
for (; env[i] != NULL; i++) {
        new[i] = my_strdup(env[i]);
        free(env[i]);
    }
    new[i] = NULL;
    free(stock);
    free(env);
    return new;
}

char *create(char **tab)
{
    int i = 0;
    char *stock = NULL;
    char *param = NULL;

    if (tab[1] != NULL && tab[2] != NULL) {
        i = (my_strlen(tab[1]) + my_strlen(tab[2]) + 2);
        param = malloc(sizeof(char) * i);
        my_strcpy(param, tab[1]);
        my_strcat(param, "=");
        my_strcat(param, tab[2]);
        stock = my_strdup(param);
        free(param);
        return stock;
    }
    return NULL;
}

char *create_env(char **tab)
{
    char *path = NULL;
    char *stock = NULL;
    char *param = NULL;

    if (tab[1] != NULL && tab[2] == NULL) {
        param = malloc(sizeof(char) * (my_strlen(tab[1]) + 2));
        my_strcpy(param, tab[1]);
        my_strcat(param, "=");
        path = my_strdup(param);
        free(param);
        return path;
    }
    stock = create(tab);
    return stock;
}

char **cpy_env(char **env, char **tab)
{
    int i = 0;
    char *stock = create_env(tab);
    int k = 0;
    char **new = NULL;

    for (i = 0; env[i] != NULL; i++);
    new = malloc(sizeof(char *) * (i + 2));
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], tab[1], my_strlen(tab[1])) == 0)
            return up_date(new, stock, env, i);
        if (my_strncmp(env[i], tab[1], my_strlen(tab[1])) != 0)
            new[i] = my_strdup(env[i]);
        free(env[i]);
    }
    new[i] = my_strdup(stock);
    i++;
    new[i] = NULL;
    free(stock);
    free(env);
    return new;
}
