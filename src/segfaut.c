/*
** EPITECH PROJECT, 2026
** segfault
** File description:
** minishell
*/

#include "my.h"

void segfault_handling(int status)
{
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status))
            mini_printf("Segmentation fault (core dumped)\n");
        if (SIGFPE == status)
            mini_printf("Floating exception (coredumped)\n");
        if (SIGFPE == status && WCOREDUMP(status)) {
            mini_printf("Segmentation fault (core dumped) ");
            mini_printf("&& Floating Point");
            mini_printf("Floating exception.\n");
        }
    }
}
