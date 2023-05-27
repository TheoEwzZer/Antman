/*
** EPITECH PROJECT, 2023
** antman
** File description:
** my_putnbr_base.c
*/

#include "antman.h"

char *my_putnbr_base2(int nbr, int base, int j)
{
    char *str = (char *)malloc(sizeof(char) * 9);
    int i = 0;

    for (; nbr > 0; i++) {
        str[i] = (char)(nbr % base + '0');
        nbr /= base;
    }
    str[i] = '\0';
    str = add_zero(str, (int)my_strlen(str), j);
    str = my_revstr(str);
    return str;
}

char *add_zero(char *str, int len, int j)
{
    for (int i = 0; i < j - len; i++)
        str = my_strcat(str, "0");
    return str;
}
