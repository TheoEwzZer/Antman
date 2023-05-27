/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** Concatenates two strings.
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strcat(char *dest, const char *src)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    int i = 0;
    char *result = malloc(sizeof(char) * (len_dest + len_src + 1));
    for (; i < len_dest; i++)
        result[i] = dest[i];
    for (; i < len_dest + len_src; i++)
        result[i] = src[i - len_dest];
    result[i] = '\0';
    return result;
}
