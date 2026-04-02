/*
** EPITECH PROJECT, 2026
** test
** File description:
** mysh
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *recup_path(char **env)
{
    char *token = NULL;
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PATH", 4) == 0) {
            return my_strdup(env[i] + 5);
        }
        i++;
    }
    return NULL;
}

char **new_path(char **env)
{
    char **tab = NULL;
    char *stock = NULL;
    int i = 0;
    char *path = recup_path(env);

    stock = strtok(path, ":");
    tab = malloc(sizeof(char *) * my_strlen(path));
    tab[0] = my_strdup(stock);
    i = 1;
    while (stock) {
        stock = strtok(NULL, ":");
        tab[i] = stock;
        i++;
    }
    return tab;
}

void process_continu(char **env, char **cmd)
{
    char *newargv[] = {NULL, ".", NULL};
    char **str = env;
    pid_t process = 0;
    int ret = 0;
    int j = 0;

    process = fork();
    if (process == 0) {
        if (chech_buitin(cmd) == 0)
            ret = execve(cmd[0], cmd, str);
        if (ret == -1) {           
            mini_printf("%s: Command not found.\n", cmd[0]);
            exit(84);
        } else
            wait(&process);
    }
    return;
}

char *split_1(void)
{
    char *cleanline = NULL;
    char *line = NULL;
    size_t len = 0;
    int k = 0;
    ssize_t llen = 0;

    llen = getline(&line, &len, stdin);
    if (llen != -1) {
        cleanline = cleanstr(line);
        return cleanline;
    }
    return cleanline;
}

int main(int argc, char **argv, char **env)
{
    int nb_rows;
    char **tab = NULL;
    char *line = NULL;
    char **new = NULL;

    new = new_env(env);
    while (1) {
        mini_printf("$> ");
        tab = my_str_to_word_array(line, &nb_rows);
        if (tab == NULL) {
            func_free(tab, line);
            continue;
        }
        new = exec_process(new, tab);
        if (exec_cmd(tab, new) == 1)
            continue;
        func_free(tab, line);
        wait(0);
    }
    return 0;
}
