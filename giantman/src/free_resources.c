/*
** EPITECH PROJECT, 2023
** antman
** File description:
** free_resources.c
*/


#include "antman.h"

int free_resources2(char *buf, var_t *var, int ret)
{
    free(buf);
    while (var->list) {
        list_t *tmp = var->list;
        var->list = var->list->next;
        free(tmp);
    }
    free(var->list);
    free(var);
    return ret;
}
