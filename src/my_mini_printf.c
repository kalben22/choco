/*
** EPITECH PROJECT, 2025
** day14
** File description:
** write the function
*/

#include "../include/my.h"

static int my_putchar(char c)
{
    return write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int my_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        i += my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb < 10) {
        i += my_putchar((nb % 10) + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        i += my_putchar((nb % 10) + 48);
    }
    return i;
}

int my_if(const char *format, int i, int count, va_list args)
{
    if (format[i] == 'i' || format[i] == 'd') {
        my_put_nbr(va_arg(args, int));
        count += 1;
    }
    if (format[i] == 's') {
        count += my_putstr(va_arg(args, char *));
    }
    if (format[i] == 'c') {
        my_putchar(va_arg(args, int));
        count += 1;
    }
    if (format[i] == '%') {
        my_putchar('%');
        count += 1;
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int i;
    int count = 0;

    va_start(args, format);
    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i++;
            count = my_if(format, i, count, args);
        } else {
            count += my_putchar(format[i]);
        }
    }
    va_end(args);
    return count;
}
