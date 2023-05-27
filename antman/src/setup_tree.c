/*
** EPITECH PROJECT, 2023
** antman
** File description:
** setup_tree.c
*/

#include "antman.h"

void setup_bin(list_t *list, char *binary)
{
    if (list && list->left && list->right) {
        setup_bin(list->left, my_strcat(binary, "0"));
        setup_bin(list->right, my_strcat(binary, "1"));
        return;
    }
    list->binary = my_strdup(binary);
    free(binary);
}

int replace_with_bin(char *buf, var_t *var)
{
    size_t len = 0;
    char *str = (char *)malloc(sizeof(char) * (my_strlen(buf) * 8));
    char *bin = "";
    size_t len_bin = 0;

    if (!str)
        return 84;
    for (size_t i = 0, k = 0; buf[i]; i++) {
        bin = search_char(var->list, buf[i]);
        len_bin = my_strlen(bin);
        for (size_t j = 0; j < len_bin; j++, k++)
            str[k] = bin[j];
        len += len_bin;
    }
    if (print_ascii(var, str, len) == 84)
        return 84;
    free(str);
    return 0;
}

char *search_char(list_t *list, char c)
{
    char *left;
    char *right;

    if (list->caractere == c && !list->left && !list->right)
        return list->binary;
    if (list->left) {
        left = search_char(list->left, c);
        if (left)
            return left;
    }
    if (list->right) {
        right = search_char(list->right, c);
        if (right)
            return right;
    }
    return NULL;
}
