/*
** EPITECH PROJECT, 2023
** antman
** File description:
** get_caracteres.c
*/

#include "antman.h"

int check_binary(char *str, list_t *list)
{
    for (unsigned int i = 0; list->binary[i]; i++) {
        if (list->binary[i] != str[i])
            return 0;
    }
    return 1;
}

list_t *get_node(struct var *var, char *str)
{
    list_t *list = var->list;

    while (list->next && !check_binary(str, list))
        list = list->next;
    return list;
}

void get_caracteres(var_t *var, char *str)
{
    list_t *list = NULL;
    unsigned int len = my_strlen(str);
    unsigned int i = 0;

    while (i < len) {
        list = get_node(var, &str[i]);
        write(1, &list->caractere, 1);
        i += my_strlen(list->binary);
    }
    free(str);
}
