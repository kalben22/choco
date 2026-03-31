/*
** EPITECH PROJECT, 2025
** printf project
** File description:
** write the headers file
*/

#ifndef MY_H
    #define MY_H

    #include <errno.h>
    #include <strings.h>
    #include <stdarg.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>

char *cleanstr(char *str);
char *split_1(void);
char **delete_env(char **tab, char **env);
int check_setenv(char **tab, char **env);
char **new_env(char **env);
int chech_buitin(char **tab);
int my_strncmp(char *s1, char *s2, int n);
char *create_env(char **tab);
char **cpy_env(char **env, char **tab);
char **exec_process(char **j, char **tab);
void process_continu(char **env, char **cmd);
int exec_cmd(char **tab, char **env);
void func_free(char **tab, char *line);
char **new_path(char **env);
int execute_func(char **env, char **cmd);
char *my_strdup(char const *src);
int mini_printf(const char *format, ...);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char *str, int *nb_rows);

#endif
