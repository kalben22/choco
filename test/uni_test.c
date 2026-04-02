/*
** EPITECH PROJECT, 2026
** unix test
** File description:
** minishell
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
cr_redirect_stdout();
cr_redirect_stderr();
}
Test(mini_printf, simple_str, . init = redirect_all_std )
{
    mini_printf("hello world in c");
    cr_assert_stdout_eq_str("hello world in c");
}
