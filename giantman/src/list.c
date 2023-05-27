/*
** EPITECH PROJECT, 2023
** antman
** File description:
** list.c
*/

#include "antman.h"

int create_linked_list(var_t *var, char *buf)
{
    int len_of_key = 0, len = 0;
    char len_of_len_key = 0;
    char c = '\0';
    var->start = 0;
    len_of_len_key = buf[0];
    for (int i = len_of_len_key, j = 1; i > 0; i--, j *= 10)
        len_of_key += (buf[i] - 48) * j;
    var->start = 1 + len_of_len_key + len_of_key;
    var->i = len_of_len_key + 1;
    c = buf[var->i];
    var->i += 1;
    len = buf[var->i];
    while (var->i < len_of_key + (len_of_len_key + 1)) {
        if (push2(c, get_binary(var, buf, len), var) == 84)
            return 84;
        c = buf[var->i];
        var->i += 1;
        len = buf[var->i];
    }
    return 0;
}

int push2(char caractere, char *binary, var_t *var)
{
    list_t *node = (list_t *)malloc(sizeof(list_t));
    list_t *last = var->list;
    if (!node)
        return 84;
    var->lead_nb += 1;
    node->caractere = caractere;
    node->occ = 0;
    node->binary = binary;
    node->next = NULL, node->daddy = NULL;
    node->left = NULL;
    node->right = NULL;
    node->valide = 1;
    if (!var->list) {
        var->list = node;
        return 0;
    }
    while (last->next)
        last = last->next;
    last->next = node;
    return 0;
}
